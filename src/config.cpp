//
// Created by gamatacy on 08.11.23.
//

#include "../include/config.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

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

void Config::updateConfig() {
    if (instance != nullptr) {

        instance = new Config();


    }
    BOOST_LOG_TRIVIAL(info) << "Config updated";
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

std::time_t Config::getMinQueueExpirationTime() {
    return this->minQueueExpirationTime;
}

std::time_t Config::getMaxQueueExpirationTime() {
    return this->maxQueueExpirationTime;
}