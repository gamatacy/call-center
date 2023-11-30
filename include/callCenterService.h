//
// Created by gamatacy on 24.11.23.
//

#ifndef CALL_CENTER_CALLCENTERSERVICE_H
#define CALL_CENTER_CALLCENTERSERVICE_H

#include <boost/log/trivial.hpp>
#include "config.h"
#include "defs.h"
#include "operatorMock.h"
#include "cdrLoggerImpl.h"
#include "vector"
#include "list"
#include "unordered_set"
#include "thread"
#include "iostream"


class CallCenterService {
private:
    std::list <Call> calls;
    std::unordered_set <size_t> callsHash;
    std::vector <OperatorMock*> operatorsList;

    void assignCall(Call*, OperatorMock*);

public:
    CallCenterService();
    ~CallCenterService();

    int handleCall(Call&);
    bool isNumberPresent(const std::string&) const;
    void handleCallsTimeout();
    void handleOperators();
};


#endif //CALL_CENTER_CALLCENTERSERVICE_H
