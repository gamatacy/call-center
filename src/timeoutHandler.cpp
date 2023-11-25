#include "../include/timeoutHandler.h"

void handleCallsTimeout(std::list<Call>& calls){
        
    while (true){
        for (auto call : calls){
            if ( call.rejectTime <= std::time(nullptr)
             && call.callStatus == CallStatus::EXPIRED)
                calls.remove(call);
    }

}