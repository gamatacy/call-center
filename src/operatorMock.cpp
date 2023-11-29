//
// Created by gamatacy on 24.11.23.
//

#include "../include/operatorMock.h"

OperatorStatus OperatorMock::getStatus() {
    return this->status;
}

std::time_t OperatorMock::getWillBeFreeTime() {
    return this->willBeFreeTime;
}

const Call *OperatorMock::getCurrentCall() {
    return this->call;
}

void OperatorMock::setStatus(OperatorStatus status) {
    this->status = status;
}

void OperatorMock::setBusy(const Call *call) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(Config::getInstance()->getMinQueueExpirationTime(),
                                                    Config::getInstance()->getMaxQueueExpirationTime());

    this->call = call;

    this->setStatus(OperatorStatus::BUSY);
    this->willBeFreeTime = std::time(nullptr) + distribution(gen);
}