//
// Created by TeUm3 on 17.11.2023.
//

#ifndef OOP_KEYBOARDINPUT_H
#define OOP_KEYBOARDINPUT_H


#include <map>
#include <string>
#include "../IInput/IInput.h"

class KeyboardInput : public IInput {
    using KeyboardLayoutMap = std::map<int, Controls>;
public:
    explicit KeyboardInput(const std::string &filename);

    ~KeyboardInput() = default;

    Controls read() override;

private:
    KeyboardLayoutMap keyboardLayoutMap;

    static KeyboardLayoutMap
    createKeyboardLayoutMap(const std::string &filename);
};


#endif //OOP_KEYBOARDINPUT_H
