//
// Created by vanya on 26.11.23.
//



#include "../include/cdr.h"

const char* callStatusStrings[] = {
        "READY",
        "PROCESSING",
        "EXPIRED",
        "OVERLOAD",
        "PROCESSED"
};

void CDR::saveCDR(const Call &call) {

    std::string filename = Config::getInstance()->getJournalFilename();

    std::fstream file;

    file.open(filename, std::fstream::app);

    if (!file.is_open()) {

        BOOST_LOG_TRIVIAL(warning) << "Файл для CDR отсутствует, попытка создать";

        file.open(filename, std::ios::out | std::ios::trunc);

        if (!file.is_open()) {
            BOOST_LOG_TRIVIAL(error) << "Не удалось создать файл для CDR";
            return;
        }
    }

    file << call.callId.id << ";"
         << call.phoneNumber.number << ";"
         << call.creationTime.time << ";"
         << call.rejectTime.time << ";"
         << call.operatorResponseTime.time << ";"
         << callStatusStrings[call.callStatus] << std::endl;

    file.close();

}