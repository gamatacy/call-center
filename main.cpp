#include <exception>
#include "include/config.h"
#include "include/httpServer.h"

int main(int argc, char **argv) {

    HttpServer *httpServer = new HttpServer();

    try {
        if (argc > 1) Config::setFilename(argv[1]);
        Config::getInstance();
    }
    catch (std::runtime_error) {
        BOOST_LOG_TRIVIAL(fatal) << "Failed to read config";
        return -1;
    }

    httpServer->listen();

    return 0;
}
