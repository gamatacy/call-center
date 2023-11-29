
#include "../include/callCenterService.h"

using namespace std::chrono_literals;

CallCenterService::CallCenterService() {

    for (int i = 0; i < 2; ++i) {
        this->operatorsList.push_back(new OperatorMock());
    }

}

CallCenterService::~CallCenterService() {}

int CallCenterService::handleCall(Call &call) {

    if (this->calls.size() == Config::getInstance()->getQuerySize()) {
        return -1;
    }

    this->calls.push_back(call);
    this->callsHash.insert(std::hash<std::string>{}(call.phoneNumber.number));
    return 1;

}

bool CallCenterService::isNumberPresent(const std::string &number) const {
    return this->callsHash.count(std::hash<std::string>{}(number)) != 0;
}

void CallCenterService::handleCallsTimeout() {

    while (true) {

        for (auto call: this->calls) {

            if (call.rejectTime <= std::time(nullptr)) {

                this->calls.remove(call);
                this->callsHash.erase(std::hash<std::string>{}(call.phoneNumber.number));

                BOOST_LOG_TRIVIAL(info) << "CallID: " << call.callId.id << " expired ";

                call.callStatus = CallStatus::EXPIRED;
                CDRLoggerImpl::getInstance()->write(call);
                break;
            }

        }


        std::this_thread::sleep_for(2000ms);

    }

}

void CallCenterService::handleOperators() {

    while (true) {

        for (auto _operator: this->operatorsList) {

            if (_operator->getWillBeFreeTime() <= std::time(nullptr)
                && _operator->getStatus() == OperatorStatus::BUSY) {

                _operator->setStatus(OperatorStatus::FREE);
                BOOST_LOG_TRIVIAL(info) << "Operator processed callID: " << _operator->getCurrentCall()->callId.id;

                Call call = *_operator->getCurrentCall();

                call.callStatus = CallStatus::PROCESSED;
                call.operatorResponseTime = std::time(nullptr);

                this->callsHash.erase(std::hash<std::string>{}(call.phoneNumber.number));

                CDRLoggerImpl::getInstance()->write(call);
            }

            if (_operator->getStatus() == OperatorStatus::FREE) {

                if (!this->calls.empty()) {

                    this->assignCall(
                            &this->calls.front(),
                            _operator
                    );
                    this->calls.pop_front();

                    BOOST_LOG_TRIVIAL(info) << "Operator processing callID: " << _operator->getCurrentCall()->callId.id;

                }

            }

        }

        std::this_thread::sleep_for(3000ms);

    }

}

void CallCenterService::assignCall(Call *call, OperatorMock *operatorMock) {

    call->callStatus = CallStatus::PROCESSING;
    operatorMock->setBusy(call);

}