//
// Created by gamatacy on 23.11.23.
//

#include "../include/httpServer.h"

void HttpServer::listen() {
    CallCenterService callCenterService;
    std::thread timeoutHandler(
        std::bind(&CallCenterService::handleCallsTimeout, &callCenterService)
    );;

    CROW_ROUTE(app, "/")([&callCenterService](const crow::request &req) {
        std::string number;
        try {
            number = std::string(req.url_params.get("number"));
        } catch (std::exception exception) {
            return crow::response(400, "Invalid number");
        }

        if (number.empty())
            return crow::response(400, "Invalid number");

        Call call;
        call.callId.id = 1;
        call.phoneNumber.number = number;
        call.callStatus  = CallStatus::READY;

        switch (callCenterService.handleCall(call))
        {
        case -1:
            return crow::response("Query is full");
        case 0:
            return crow::response("Processing call");
        case 1:
            return crow::response("You are in queue");
        }

        return crow::response(number);
    });


    app.port(29501).multithreaded().run();
}