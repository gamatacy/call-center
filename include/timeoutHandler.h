#ifndef CALL_CENTER_TIMEOUTHANDLER_H
#define CALL_CENTER_TIMEOUTHANDLER_H

#include "list"
#include "ctime"
#include "chrono"
#include "defs.h"
#include "status.h"

void handleCallsTimeout(const std::list<Call>&);

#endif //CALL_CENTER_TIMEOUTHANDLER_H