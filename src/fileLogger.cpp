//
// Created by vanya on 29.11.23.
//

#include "../include/fileLogger.h"

template<class T>
FileLogger<T>::FileLogger(const std::string &fname) {

    this->filename = fname;

    FileLogger::file.open(filename, std::fstream::app);

    if (!FileLogger::file.is_open()) {

        FileLogger::file.open(filename, std::ios::out | std::ios::trunc);

        if (!FileLogger::file.is_open()) {
            BOOST_LOG_TRIVIAL(error) << "Не удалось создать файл для CDR";
        }
    }

}

template<class T>
FileLogger<T>::~FileLogger() {
    FileLogger::file.close();
}

template<class T>
std::fstream &FileLogger<T>::getFile() {
    return this->file;
}

template<class T>
std::string FileLogger<T>::getFileName() const {
    return DEFAULT_LOG_FILE;
}

template<class T>
void FileLogger<T>::setFileName(const std::string &filename) {
    this->filename = filename;
}

template
class FileLogger<Call>;

