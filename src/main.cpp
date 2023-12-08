#include "Game/Game.h"
#include "GameMenu/GameMenu.h"
#include "FileConfigReader/FileConfigReader.h"

void updateLocale();

#ifdef _WIN32

#include <windows.h> // для функции SetConsoleOutputCP и константы CP_UTF8

void updateLocale() {
    std::setlocale(LC_ALL, "ru_RU.UTF8");

    SetConsoleOutputCP(CP_UTF8);
}

#elif __linux__

void updateLocale() {
    std::setlocale(LC_ALL, "ru_RU.UTF8");
}

#endif

int main(int argc, char const *argv[]) {
    updateLocale();

    std::string fileName = "../input.txt";
    FileConfigReader fileConfigReader(fileName);
    if (!fileConfigReader.is_open()) {
        std::cout << "Could not open file: " << fileName;
        return 0;
    }

    ControlMap keyBoardLayout;
    try {
        keyBoardLayout = fileConfigReader.readConfig();
    } catch (const std::exception &e) {
        std::cout << e.what();
        return 0;
    }

    IInput *input = new KeyboardInput(keyBoardLayout);


    GameMenu menu(input);
    menu.start();

    return 0;
}

