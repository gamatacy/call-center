//
// Created by gamatacy on 23.11.23.
//

#ifndef CALL_CENTER_STATUS_H
#define CALL_CENTER_STATUS_H

static const char* callStatusStrings[] = {
        "READY",
        "PROCESSING",
        "EXPIRED",
        "OVERLOAD",
        "PROCESSED"
};

enum CallStatus {
    READY,
    PROCESSING,
    EXPIRED,
    OVERLOAD,
    PROCESSED
};

enum OperatorStatus {
    FREE,
    BUSY
};

#endif //CALL_CENTER_STATUS_H
