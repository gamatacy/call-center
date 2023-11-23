//
// Created by gamatacy on 23.11.23.
//

#include "../include/httpServer.h"

void HttpServer::listen() {

    CROW_ROUTE(app, "/")([](const crow::request &req) {
        std::string number;

        try {
            number = std::string(req.url_params.get("number"));
        } catch (std::exception exception) {
            return crow::response(400, "Ne ponyal!?");
        }

        if (number.empty())
            return crow::response(400, "Bad Request");

        return crow::response(number);
    });

    app.port(29501).multithreaded().run();
}