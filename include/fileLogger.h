//
// Created by vanya on 29.11.23.
//

#ifndef CALL_CENTER_FILELOGGER_H
#define CALL_CENTER_FILELOGGER_H

#define DEFAULT_LOG_FILE "logs.txt"

#include <boost/log/trivial.hpp>
#include <string>
#include <iostream>

#include <fstream>
#include "config.h"

#include "defs.h"

template<typename T>
class FileLogger {
private:
    std::string filename;
    std::fstream file;

public:

    FileLogger(const std::string&);

    ~FileLogger();

    FileLogger(const FileLogger &obj) = delete;

    void operator=(FileLogger const &) = delete;

    void setFileName(const std::string &);

    std::fstream &getFile();

    virtual std::string getFileName() const;

    virtual void write(const T &) = 0;

};


#endif //CALL_CENTER_FILELOGGER_H
