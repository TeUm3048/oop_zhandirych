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

    unsigned temp = 0;
    do {
        std::cout << "Enter new HP: ";
        std::cin >> temp;
        _player.setHP(temp);
    } while (_player.isAlive());
}

void PlayerController::playerMove(Direction direction) {
    switch (direction) {
        case Direction::Up:
            _player.setY(_player.getY() + 1);
        case Direction::Down:
            _player.setY(_player.getY() - 1);
        case Direction::Left:
            _player.setX(_player.getX() - 1);
        case Direction::Right:
            _player.setX(_player.getX() + 1);
    }
}
