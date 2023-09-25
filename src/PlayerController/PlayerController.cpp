#include <iostream>
#include "PlayerController.h"

PlayerController::PlayerController(Player &player) : _player(player) {
}

PlayerController::~PlayerController() {
}

void PlayerController::start() {
    std::string name;
    std::cout << "Enter your nickname: ";
    std::cin >> name;


    _player->setName(name);
    unsigned temp = 0;
    do {
        std::cin >> temp;
        _player->setHP(temp);
    } while (temp != 0);
}