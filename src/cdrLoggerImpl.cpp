//
// Created by vanya on 26.11.23.
//

#include "../include/cdrLoggerImpl.h"

CDRLoggerImpl *CDRLoggerImpl::instance = nullptr;

void CDRLoggerImpl::write(const Call &call) {
    
    getFile() << call.callId.id << ";"
              << call.phoneNumber.number << ";"
              << call.creationTime.time << ";"
              << call.rejectTime.time << ";"
              << call.operatorResponseTime.time << ";"
              << callStatusStrings[call.callStatus] << std::endl;

}

std::string CDRLoggerImpl::getFileName() const {
    return Config::getInstance()->getJournalFilename();
}

