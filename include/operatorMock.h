//
// Created by gamatacy on 24.11.23.
//

#ifndef CALL_CENTER_OPERATORMOCK_H
#define CALL_CENTER_OPERATORMOCK_H

#include "status.h"
#include "defs.h"
#include "ctime"
#include "config.h"
#include "random"

class OperatorMock {
private:
    OperatorStatus status;
    const Call* call;
    std::time_t willBeFreeTime;
public:
    OperatorMock() : status(FREE) {};

    OperatorStatus getStatus();
    std::time_t getWillBeFreeTime();
    const Call* getCurrentCall();

    void setStatus(OperatorStatus);
    void setBusy(const Call*);
};

#endif //CALL_CENTER_OPERATORMOCK_H
