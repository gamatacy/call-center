//
// Created by gamatacy on 23.11.23.
//

#include "../include/httpServer.h"

uint64_t HttpServer::id = 0;

void HttpServer::listen() {
    CallCenterService callCenterService;
    std::thread timeoutHandler(
    std::bind(&CallCenterService::handleCallsTimeout, &callCenterService)
    );
    std::thread operatorsHandler(
    std::bind(&CallCenterService::handleOperators, &callCenterService)
    );

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

        BOOST_LOG_TRIVIAL(info) << "New request by " << number << " number";

        Call call;
        call.callId = HttpServer::id++;
        call.phoneNumber = number;
        call.creationTime = std::time(nullptr);
        call.rejectTime = std::time(nullptr);
        call.callStatus = CallStatus::READY;

        switch (callCenterService.handleCall(call)) {
            case -1:
                BOOST_LOG_TRIVIAL(info) << number << " rejected because of full queue";
                call.callStatus = CallStatus::OVERLOAD;
                CDRLoggerImpl::getInstance()->write(call);
                return crow::response("Query is full");
            case 1:
                BOOST_LOG_TRIVIAL(info) << number << " added to queue";
                return crow::response("You are in queue");
        }

        return crow::response(number);
    });


    app.port(29501).multithreaded().run();
}