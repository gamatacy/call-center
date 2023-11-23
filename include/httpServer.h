//
// Created by gamatacy on 23.11.23.
//

#ifndef CALL_CENTER_HTTPSERVER_H
#define CALL_CENTER_HTTPSERVER_H

#include "crow_all.h"
#include "string"

class HttpServer {
private:
    crow::SimpleApp app;
public:
    HttpServer() {};

    void listen();

};


#endif //CALL_CENTER_HTTPSERVER_H
