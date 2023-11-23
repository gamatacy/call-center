//
// Created by gamatacy on 23.11.23.
//

#ifndef CALL_CENTER_DEFS_H
#define CALL_CENTER_DEFS_H

#include "stdint.h"

struct CallId {
    uint64_t id;

    CallId(uint64_t id) {
        this->id = id
    }

    explicit operator uint64_t() {
        return *this->id
    }

};

struct CreationTime {
    uint64_t time;

    CreationTime(uint64_t time) {
        this->time = time
    }

    explicit operator uint64_t() {
        return *this->time
    }
};

struct RejectTime{
    uint64_t time;

    RejectTime(uint64_t time){
        this->time = time
    }

    explicit operator uint64_t(){
        return *this->time
    }

};

struct Call {
    CallId callId;
    CreationTime creationTime;
    RejectTime rejectTime;
};

#endif //CALL_CENTER_DEFS_H
