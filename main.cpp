#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "include/config.h"
#include "include/httpServer.h"

int main() {

    HttpServer *httpServer = new HttpServer();

    httpServer->listen();

    return 0;
}
