//
// Created by gamatacy on 08.11.23.
//

#ifndef CALL_CENTER_CONFIG_H
#define CALL_CENTER_CONFIG_H
#define CFG_FILE "cfg.json"

#include <boost/log/trivial.hpp>

#include "stdint.h"
#include "ctime"
#include "string"


class Config {
private:
    static Config *instance;
    uint32_t querySize = 1;
    std::time_t responseMin = 0;
    std::time_t responseMax = 1000;
    std::string journalFilename;
    Config();
public:
    Config(const Config& obj) = delete;
    void operator=(Config const&) = delete;
    uint32_t getQuerySize();
    std::time_t getResponseMin();
    std::time_t getResponseMax();
    std::string getJournalFilename();

    static Config* getInstance()  {
        if (instance == nullptr) { instance = new Config(); }
        return instance;
    }

};


#endif //CALL_CENTER_CONFIG_H
