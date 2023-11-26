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
    this->journalFilename = pt.get<std::string>("journal_filename");

    BOOST_LOG_TRIVIAL(info) << "query_size: " << this->querySize;
    BOOST_LOG_TRIVIAL(info) << "min_response_time: " << this->responseMin;
    BOOST_LOG_TRIVIAL(info) << "max_response_time: " << this->responseMax;
    BOOST_LOG_TRIVIAL(info) << "journal_filename: " << this->journalFilename;

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
