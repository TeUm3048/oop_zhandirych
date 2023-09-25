#include <iostream>
#include "PlayerController.h"

PlayerController::PlayerController(Player &player) : _player(player) {
}

PlayerController::~PlayerController() {
}

void PlayerController::start() {
    std::string name;

    bool nameIsSet = false;
    while (!nameIsSet) {
        std::cout << "Enter your nickname: ";
        std::cin >> name;
        try {
            _player.setName(name);
            nameIsSet = true;
        } catch (const std::invalid_argument &e) {
            std::cout << e.what() << '\n';
        }
    }


    _player->setName(name);
    unsigned temp = 0;
    do {
        std::cin >> temp;
        _player.setHP(temp);
    } while (_player.isAlive());
}