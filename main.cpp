#include <exception>
#include "include/config.h"
#include "include/httpServer.h"

#define DEFAULT_PORT 29501

int main(int argc, char **argv) {

    HttpServer *httpServer = new HttpServer();
    int port = DEFAULT_PORT;

    try {
        if (argc > 1) Config::setFilename(argv[1]);
        Config::getInstance();
    }
    catch (std::runtime_error) {
        BOOST_LOG_TRIVIAL(fatal) << "Failed to read config";
        return -1;
    }

    if (argc > 2) port = atoi(argv[2]);
    else BOOST_LOG_TRIVIAL(warning) << "Failed to read port, using default 29501";

    httpServer->listen(port);

    return 0;
}
