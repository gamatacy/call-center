//
// Created by gamatacy on 24.11.23.
//

#ifndef CALL_CENTER_OPERATORMOCK_H
#define CALL_CENTER_OPERATORMOCK_H

#include "status.h"
#include "defs.h"

class OperatorMock {
private:
    OperatorStatus status;

public:
    OperatorMock() : status(FREE) {};

    OperatorStatus getStatus();
    void assign(const Call& call);

};


#endif //CALL_CENTER_OPERATORMOCK_H
