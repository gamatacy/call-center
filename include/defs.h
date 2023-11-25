//
// Created by gamatacy on 23.11.23.
//

#ifndef CALL_CENTER_DEFS_H
#define CALL_CENTER_DEFS_H

#include "stdint.h"
#include "ctime"
#include "string"
#include "status.h"

struct CallId {
    uint64_t id;

    CallId() = default;
    CallId(uint64_t id) : id(id) {}

    explicit operator uint64_t() {
        return this->id;
    }

};

struct PhoneNumber {
    std::string number;

    PhoneNumber() = default;
    PhoneNumber(std::string number) : number(number) {}

    explicit operator std::string() {
        return this->number;
    }

};

struct AbstractTime {
    std::time_t time;

    AbstractTime() = default;
    AbstractTime(std::time_t time) : time(time) {}

    explicit operator std::time_t() {
        return this->time;
    }

    int operator <=(const std::time_t& time){
        return this->time <= time;
    }

    int operator ==(const AbstractTime& abstractTime){
        return this->time == abstractTime.time;
    }

};

struct CreationTime : public AbstractTime {
};
struct RejectTime : public AbstractTime {
};
struct OperatorResponseTime : public AbstractTime {
};


struct Call {
    CallId callId;
    PhoneNumber phoneNumber;
    CreationTime creationTime;
    RejectTime rejectTime;
    OperatorResponseTime operatorResponseTime;
    CallStatus callStatus;

    Call() = default;

    bool operator==(const Call& call) const {
        return this->callId.id == call.callId.id;
    }

};

#endif //CALL_CENTER_DEFS_H
