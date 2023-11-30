//
// Created by vanya on 26.11.23.
//

#include "../include/cdrLoggerImpl.h"

CDRLoggerImpl *CDRLoggerImpl::instance = nullptr;

void CDRLoggerImpl::write(const Call &call) {

    char timeString[80];

    getFile() << call.callId.id << ";"
              << call.phoneNumber.number << ";";

    strftime(timeString, 80, "%Y-%m-%d %H:%M:%S", localtime(&call.creationTime.time));
    getFile() << timeString << ";";

    strftime(timeString, 80, "%Y-%m-%d %H:%M:%S", localtime(&call.rejectTime.time));
    getFile() << timeString << ";";

    strftime(timeString, 80, "%Y-%m-%d %H:%M:%S", localtime(&call.operatorResponseTime.time));
    getFile() << timeString << ";"
                << callStatusStrings[call.callStatus] << std::endl;

}

std::string CDRLoggerImpl::getFileName() const {
    return Config::getInstance()->getJournalFilename();
}

