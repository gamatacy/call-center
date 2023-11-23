//
// Created by gamatacy on 08.11.23.
//

#ifndef CALL_CENTER_CONFIG_H
#define CALL_CENTER_CONFIG_H
#define CFG_FILE "cfg.json"
#include "stdint.h"

class Config {
private:
    static Config *instance;
    uint32_t querySize = 1;
    Config();
public:
    Config(const Config& obj) = delete;
    void operator=(Config const&) = delete;
    uint32_t getQuerySize();

    static Config* getInstance()  {
        if (instance == nullptr) instance = new Config();
        return instance;
    }

};


#endif //CALL_CENTER_CONFIG_H
