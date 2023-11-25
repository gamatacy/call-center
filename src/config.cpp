//
// Created by gamatacy on 08.11.23.
//

#include "../include/config.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

Config* Config::instance = nullptr;

Config::Config() {
    boost::property_tree::ptree pt;
    boost::property_tree::read_json(CFG_FILE, pt);
    this->querySize = pt.get<uint32_t>("query_size");
}

uint32_t Config::getQuerySize() {
    return this->querySize;
}

std::time_t Config::getResponseMin(){
    return this->responseMin;
}

std::time_t Config::getResponseMax(){
    return this->responseMax;
}
