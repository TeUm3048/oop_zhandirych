//
// Created by TeUm3 on 17.11.2023.
//

#ifndef OOP_FILECONFIGREADER_H
#define OOP_FILECONFIGREADER_H


#include <fstream>
#include <string>
#include "../IConfigReader/IConfigReader.h"

class FileConfigReader : public IConfigReader {
private:
    std::ifstream file;

public:
    explicit FileConfigReader(const std::string &fileName);

    ~FileConfigReader();

    bool readLine(std::string &line);

    bool is_open();


    ControlMap readConfig() override;

};


#endif //OOP_FILECONFIGREADER_H
