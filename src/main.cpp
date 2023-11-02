#include "Player/Player.h"
#include "PlayerView/PlayerView.h"
#include "PlayerController/PlayerController.h"
#include "FieldCreator/FieldCreator.h"
void updateLocale() ;

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
    Player player;
    FieldCreator fieldCreator;
    Field field = fieldCreator.createFieldForLevel(2);
    PlayerView view(player);
    PlayerController controller(player, field);

    controller.start();


    return 0;
}

