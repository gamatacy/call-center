//
// Created by gamatacy on 23.11.23.
//

#ifndef CALL_CENTER_DEFS_H
#define CALL_CENTER_DEFS_H

#include "stdint.h"
#include "status.h"
#include "config.h"
#include "ctime"
#include "string"
#include "iostream"
#include "random"

struct CallId {
    uint64_t id;

    CallId() = default;

    CallId &operator=(uint64_t id) {
        this->id = id;
        return *this;
    }

    explicit operator uint64_t() {
        return this->id;
    }

};

struct PhoneNumber {
    std::string number;

    PhoneNumber() = default;

    PhoneNumber &operator=(std::string number) {
        this->number = number;
        return *this;
    }

    explicit operator std::string() {
        return this->number;
    }

};

struct AbstractTime {
    std::time_t time;

    AbstractTime() = default;

    AbstractTime &operator=(std::time_t time) {
        this->time = time;
        return *this;
    }

    explicit operator std::time_t() {
        return this->time;
    }

    int operator<=(const std::time_t &time) {
        return this->time <= time;
    }

    int operator==(const AbstractTime &abstractTime) {
        return this->time == abstractTime.time;
    }

};

struct CreationTime : public AbstractTime {
    CreationTime &operator=(std::time_t time) {
        this->time = time;
        return *this;
    }
};

struct RejectTime : public AbstractTime {
    RejectTime &operator=(std::time_t time) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> distribution(Config::getInstance()->getResponseMin(),
                                                        Config::getInstance()->getResponseMax());
        this->time = time + distribution(gen);
        return *this;
    }
};

struct OperatorResponseTime : public AbstractTime {
    OperatorResponseTime &operator=(std::time_t time) {
        this->time = time;
        return *this;
    }
};

struct Call {
    CallId callId;
    PhoneNumber phoneNumber;
    CreationTime creationTime;
    RejectTime rejectTime;
    OperatorResponseTime operatorResponseTime;
    CallStatus callStatus;

    Call() = default;

    bool operator==(const Call &call) const {
        return this->callId.id == call.callId.id;
    }

};


#endif //CALL_CENTER_DEFS_H
