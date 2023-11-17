//
// Created by TeUm3 on 17.11.2023.
//

#ifndef OOP_FILEREADER_H
#define OOP_FILEREADER_H


#include <fstream>
#include <string>

class FileReader {
private:
    std::ifstream file;

public:
    explicit FileReader(const std::string &fileName);

    ~FileReader();

    bool readLine(std::string &line);
};


#endif //OOP_FILEREADER_H
