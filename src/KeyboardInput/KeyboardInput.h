//
// Created by TeUm3 on 17.11.2023.
//

#ifndef OOP_KEYBOARDINPUT_H
#define OOP_KEYBOARDINPUT_H


#include <map>
#include <string>
#include "../IInput/IInput.h"
#include "../Controls/ControlMap.h"

class KeyboardInput : public IInput {
public:
//    explicit KeyboardInput(const std::string &filename);

    explicit KeyboardInput(ControlMap &keyboardLayoutMap);

    Controls read() override;

private:
    ControlMap &keyboardLayoutMap;

    static ControlMap
    createKeyboardLayoutMap(const std::string &filename);
};


#endif //OOP_KEYBOARDINPUT_H
