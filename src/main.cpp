#include "Player/Player.h"
#include "PlayerView/PlayerView.h"
#include "PlayerController/PlayerController.h"


int main(int argc, char const *argv[]) {
    Player player;
    PlayerView view(player);
    PlayerController controller(player);
    controller.start();

    return 0;
}

