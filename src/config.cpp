//
// Created by gamatacy on 08.11.23.
//

#include "../include/config.h"

Config *Config::instance = nullptr;

Config::Config() {
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(CFG_FILE, pt);


    this->querySize = pt.get<uint32_t>("query_size");
    this->responseMin = pt.get<uint32_t>("min_response_time");
    this->responseMax = pt.get<uint32_t>("max_response_time");
    this->minQueueExpirationTime = pt.get<uint32_t>("min_queue_expiration_time");
    this->maxQueueExpirationTime = pt.get<uint32_t>("max_queue_expiration_time");
    this->journalFilename = pt.get<std::string>("journal_filename");
}

using namespace std::chrono_literals;

void Config::updateConfig() {

    while(true){
        try {
            Config *config = new Config();
            Config::instance = config;
            BOOST_LOG_TRIVIAL(info) << "Config updated";
        } catch (std::runtime_error) {
            BOOST_LOG_TRIVIAL(warning) << "Failed to update config";
        }

        std::this_thread::sleep_for(10s);
    }

}

uint32_t Config::getQuerySize() {
    return this->querySize;
}

std::time_t Config::getResponseMin() {
    return this->responseMin;
}

std::time_t Config::getResponseMax() {
    return this->responseMax;
}

std::string Config::getJournalFilename() {
    return this->journalFilename;
}
