//
// Created by gamatacy on 08.11.23.
//

#ifndef CALL_CENTER_CONFIG_H
#define CALL_CENTER_CONFIG_H
#define CFG_FILE "cfg.json"
#include "stdint.h"
#include "ctime"

class Config {
private:
    static Config *instance;
    uint32_t querySize = 1;
    std::time_t responseMin = 0;
    std::time_t responseMax = 5000;
    Config();
public:
    Config(const Config& obj) = delete;
    void operator=(Config const&) = delete;
    uint32_t getQuerySize();
    std::time_t getResponseMin();
    std::time_t getResponseMax();

    static Config* getInstance()  {
        if (instance == nullptr) { instance = new Config(); }
        return instance;
    }

};


#endif //CALL_CENTER_CONFIG_H
