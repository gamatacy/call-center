//
// Created by vanya on 26.11.23.
//

#ifndef CALL_CENTER_CDRLOGGERIMPL_H
#define CALL_CENTER_CDRLOGGERIMPL_H

#include <boost/log/trivial.hpp>
#include <iostream>
#include <fstream>

#include "defs.h"
#include "config.h"
#include "status.h"
#include "fileLogger.h"

class CDRLoggerImpl : public FileLogger<Call> {
private:
    static CDRLoggerImpl *instance;

    CDRLoggerImpl() : FileLogger<Call>(
            Config::getInstance()->getJournalFilename()
    ) {}

public:

    virtual void write(const Call &call) override;

    std::string getFileName() const override;

    static FileLogger *getInstance() {
        if (instance == nullptr) { instance = new CDRLoggerImpl(); }
        return instance;
    }

};

#endif //CALL_CENTER_CDRLOGGERIMPL_H
