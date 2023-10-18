#include "Player/Player.h"
#include "PlayerView/PlayerView.h"
#include "PlayerController/PlayerController.h"
#include "FieldCreator/FieldCreator.h"


int main(int argc, char const *argv[]) {
    std::setlocale(LC_ALL, "ru_RU.UTF-8");
    Player player;
    FieldCreator fieldCreator;
    Field field = fieldCreator.createFieldForLevel(1);
    PlayerView view(player);
    PlayerController controller(player, field);

    controller.start();


    return 0;
}

