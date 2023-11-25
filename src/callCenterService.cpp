//
// Created by gamatacy on 24.11.23.
//

#include "../include/callCenterService.h"

CallCenterService::CallCenterService() {}

int CallCenterService::handleCall(Call& call){

    if (this->hasFreeOperators() == 1 && this->operatorsList.size() < 3){
        call.callStatus == CallStatus::PROCESSING;
        return 0;
    }
    else if (this->calls.size() == Config::getInstance()->getQuerySize()){
        return -1;
    }

    this->calls.push_back(call);
    return 1;

}

int CallCenterService::hasFreeOperators(){
    for (OperatorMock operatorMock : this->operatorsList){
        if (operatorMock.getStatus() == OperatorStatus::FREE){
            return 1;
        }
    }
    return 0;
}

void CallCenterService::handleCallsTimeout(){
        
    while (true){
        for (auto call : this->calls){
            if ( call.rejectTime <= std::time(nullptr)
             && call.callStatus == CallStatus::EXPIRED)
                this->calls.remove(call);
        }
    }

}