//
// Created by gamatacy on 08.11.23.
//

#ifndef CALL_CENTER_CONFIG_H
#define CALL_CENTER_CONFIG_H
#define CFG_FILE "cfg.json"

#include <boost/log/trivial.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <exception>

#include "stdint.h"
#include "ctime"
#include "string"
#include "thread"


class Config {
private:
    static Config *instance;
    uint32_t querySize;
    std::time_t responseMin;
    std::time_t responseMax;
    std::time_t minQueueExpirationTime;
    std::time_t maxQueueExpirationTime;
    std::string journalFilename;

    Config();

public:
    Config(const Config &obj) = delete;

    void operator=(Config const &) = delete;

    uint32_t getQuerySize();

    std::time_t getResponseMin();

    std::time_t getResponseMax();

    std::time_t getMinQueueExpirationTime();

    std::time_t getMaxQueueExpirationTime();

    std::string getJournalFilename();

    static Config *getInstance() {
        if (instance == nullptr) { instance = new Config(); }
        return instance;
    }

    static void updateConfig();

};


#endif //CALL_CENTER_CONFIG_H
