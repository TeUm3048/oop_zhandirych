#include "Game/Game.h"
#include "GameMenu/GameMenu.h"

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

    GameMenu menu;
    menu.start();

    return 0;
}

