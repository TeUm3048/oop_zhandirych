//
// Created by TeUm3 on 17.11.2023.
//

#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <conio.h>
#include "KeyboardInput.h"
#include "../utils/FileReader.h"

KeyboardInput::KeyboardInput(const std::string &filename) {
    keyboardLayoutMap = createKeyboardLayoutMap(filename);
}

Controls KeyboardInput::read() {
    int c = getch();
    return keyboardLayoutMap[c];
}
KeyboardInput::KeyboardLayoutMap
KeyboardInput::createKeyboardLayoutMap(const std::string &filename)  {
    KeyboardLayoutMap dictionary;
    FileReader fileReader(filename);
    std::ifstream input_file(filename);

    // Perform dictionary from file
    for (std::string line; fileReader.readLine(line);) {
        size_t space_pos = line.find(' ');
        if (space_pos == std::string::npos) {
            throw std::runtime_error(
                    "Неправильно сформированная строка: " + line);
        }
        std::string key = line.substr(0, space_pos);
        std::string value = line.substr(space_pos + 1);

        dictionary[std::stoi(key)] = static_cast<Controls>(std::stoi(value));
    }

    //    Validate dictionary
    if (dictionary.empty()) {
        throw (std::invalid_argument("В указанном файле нет комманд"));
    }
    std::vector<Controls> values;
    for (const auto &entry: dictionary) {
        values.push_back(entry.second);
    }
    for (const auto &entry: dictionary) {
        if (std::count(values.cbegin(), values.cend(), entry.second) > 1)
            throw std::runtime_error(
                    "Значение " + std::to_string(entry.first) + " " +
                    std::to_string(entry.second) + " не уникально");
    }
    return dictionary;
}


