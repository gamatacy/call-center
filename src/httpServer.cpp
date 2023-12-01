//
// Created by gamatacy on 23.11.23.
//

#include "../include/httpServer.h"

// TODO: normal id generation, pretty writing to file, tests

uint64_t HttpServer::id = 0;

void HttpServer::listen(const int& port) {
    CallCenterService callCenterService;

    std::thread timeoutHandler(
    std::bind(&CallCenterService::handleCallsTimeout, &callCenterService)
    );

    std::thread operatorsHandler(
    std::bind(&CallCenterService::handleOperators, &callCenterService)
    );

    std::thread configUpdater(Config::updateConfig);

    CROW_ROUTE(app, "/")([&callCenterService](const crow::request &req) {
        std::string number;

        try {
            number = std::string(req.url_params.get("number"));
        } catch (std::exception exception) {
            BOOST_LOG_TRIVIAL(info) << "Failed to process request: Invalid number";
            return crow::response(400, "Invalid number");
        }

        if (number.empty()) {
            BOOST_LOG_TRIVIAL(info) << "Failed to process request: Invalid number";
            return crow::response(400, "Invalid number");
        }

        if (callCenterService.isNumberPresent(number)) {
            BOOST_LOG_TRIVIAL(info) << number << " already in queue";
            return crow::response(400, "This number's already in queue");
        }

        BOOST_LOG_TRIVIAL(info) << "New request by " << number << " number";

        Call call;
        call.callId = HttpServer::id++;
        call.phoneNumber = number;
        call.creationTime = std::time(nullptr);
        call.rejectTime = std::time(nullptr);
        call.operatorResponseTime = std::time(nullptr);
        call.callStatus = CallStatus::READY;

        switch (callCenterService.handleCall(call)) {
            case -1:
                BOOST_LOG_TRIVIAL(info) << "CallID: " << call.callId.id << " rejected because of full queue";
                call.callStatus = CallStatus::OVERLOAD;
                CDRLoggerImpl::getInstance()->write(call);
                return crow::response("CallID: " + std::to_string(call.callId.id) + ". Query is full");
            case 1:
                BOOST_LOG_TRIVIAL(info) << "CallID: " << call.callId.id << " added to queue";
                return crow::response("CallID: " + std::to_string(call.callId.id) + ". You are in queue");
        }

        return crow::response(number);
    });


    app.port(port).multithreaded().run();
}