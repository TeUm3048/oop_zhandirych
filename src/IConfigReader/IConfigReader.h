//
// Created by TeUm3 on 24.11.2023.
//

#ifndef OOP_ICONFIGREADER_H
#define OOP_ICONFIGREADER_H

#include "../Controls/ControlMap.h"

class IConfigReader {
public:

    virtual ControlMap readConfig() = 0;

};

#endif //OOP_ICONFIGREADER_H
