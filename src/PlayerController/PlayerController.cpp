#include <iostream>
#include "PlayerController.h"

PlayerController::PlayerController(Player &player) : _player(player),
                                                     _field(Field()) {
}

PlayerController::PlayerController(Player &player, Field &field) : _player(
        player), _field(field) {
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
    Coordinate new_coord{};
    switch (direction) {
        case Direction::Up:
            new_coord = {_player.getX(), _player.getY() + 1};
            break;
        case Direction::Down:
            new_coord = {_player.getX(), _player.getY() - 1};
            break;
        case Direction::Left:
            new_coord = {_player.getX() - 1, _player.getY()};
            break;
        case Direction::Right:
            new_coord = {_player.getX() + 1, _player.getY()};
            break;
    }
    if (canMove(new_coord))
        _player.setCoordinate(new_coord);
}

void PlayerController::changeField(Field &field) {
    _field = field;
}

bool PlayerController::canMove(int x, int y) {
    return !_field.getFieldCeil(x, y).isOccupied();
}

bool PlayerController::canMove(Coordinate coord) {
    return canMove(coord.x, coord.y);
}

