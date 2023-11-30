//
// Created by gamatacy on 08.11.23.
//

#include "../include/config.h"

Config *Config::instance = nullptr;
std::string Config::filename = CFG_FILE;

Config::Config() {
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(Config::filename, pt);

    this->querySize = pt.get<uint32_t>("query_size");
    this->operatorsCount = pt.get<uint32_t>("operators_count");
    this->responseMin = pt.get<uint32_t>("min_response_time");
    this->responseMax = pt.get<uint32_t>("max_response_time");
    this->minQueueExpirationTime = pt.get<uint32_t>("min_queue_expiration_time");
    this->maxQueueExpirationTime = pt.get<uint32_t>("max_queue_expiration_time");
    this->journalFilename = pt.get<std::string>("journal_filename");

}

void Config::deleteInstance() {
    instance = nullptr;
}

void Config::setFilename(const std::string &filename) {

    Config::filename = filename;

}

using namespace std::chrono_literals;

void Config::updateConfig() {

    while (true) {
        try {
            Config *config = new Config();
            auto tmp = Config::instance;
            Config::instance = config;
            delete tmp;
            BOOST_LOG_TRIVIAL(info) << "Config updated";
        } catch (std::runtime_error) {
            BOOST_LOG_TRIVIAL(warning) << "Failed to update config";
        }

        std::this_thread::sleep_for(30s);
    }

}

uint32_t Config::getQuerySize() {
    return this->querySize;
}

uint32_t Config::getOperatorsCount() {
    return this->operatorsCount;
}

std::time_t Config::getResponseMin() {
    return this->responseMin;
}

std::time_t Config::getResponseMax() {
    return this->responseMax;
}

std::time_t Config::getMinQueueExpirationTime() {
    return this->minQueueExpirationTime;
}

std::time_t Config::getMaxQueueExpirationTime() {
    return this->maxQueueExpirationTime;
}

std::string Config::getJournalFilename() {
    return this->journalFilename;
}
