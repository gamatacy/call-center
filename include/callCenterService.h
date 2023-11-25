//
// Created by gamatacy on 24.11.23.
//

#ifndef CALL_CENTER_CALLCENTERSERVICE_H
#define CALL_CENTER_CALLCENTERSERVICE_H

#include "list"
#include "thread"
#include "vector"
#include "defs.h"
#include "operatorMock.h"
#include "config.h"


class CallCenterService {
private:
    std::list <Call> calls;
    std::vector <OperatorMock> operatorsList;

    int hasFreeOperators();

public:
    CallCenterService();

    int handleCall(Call&);    
    void handleCallsTimeout();

};


#endif //CALL_CENTER_CALLCENTERSERVICE_H
