//
// Created by gamatacy on 23.11.23.
//

#ifndef CALL_CENTER_HTTPSERVER_H
#define CALL_CENTER_HTTPSERVER_H

#include <boost/log/trivial.hpp>
#include "crow_all.h"
#include "callCenterService.h"
#include "cdr.h"
#include "stdint.h"
#include "string"
#include "thread"

class HttpServer {
private:
    crow::SimpleApp app;
public:
    static uint64_t id;

    HttpServer() {};

    void listen();

};


#endif //CALL_CENTER_HTTPSERVER_H
