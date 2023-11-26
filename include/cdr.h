//
// Created by vanya on 26.11.23.
//

#ifndef CALL_CENTER_CDR_H
#define CALL_CENTER_CDR_H

#include <boost/log/trivial.hpp>
#include "iostream"
#include "fstream"
#include "defs.h"
#include "config.h"

class CDR {
public:
    static void saveCDR(const Call&);
};


#endif //CALL_CENTER_CDR_H
