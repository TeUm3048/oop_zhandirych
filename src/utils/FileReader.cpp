//
// Created by TeUm3 on 17.11.2023.
//

#include "FileReader.h"

FileReader::FileReader(const std::string &fileName) {
    file.open(fileName, std::ios::in | std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + fileName);
    }
}

FileReader::~FileReader() {
    if (file.is_open()) {
        file.close();
    }
}

bool FileReader::readLine(std::string &line) {
    if (std::getline(file, line)) {
        return true;
    }
    return false;
}

