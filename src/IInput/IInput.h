//
// Created by TeUm3 on 17.11.2023.
//

#ifndef OOP_IINPUT_H
#define OOP_IINPUT_H


#include "../Controls/Controls.h"

class IInput {
public:
    virtual Controls read() = 0;

};


#endif //OOP_IINPUT_H
