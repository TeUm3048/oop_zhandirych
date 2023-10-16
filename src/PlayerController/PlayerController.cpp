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
//        std::cout << "Enter your nickname: ";
//        std::cin >> name;
        name = "default";
        try {
            _player.setName(name);
            nameIsSet = true;
        } catch (const std::invalid_argument &e) {
            std::cout << e.what() << '\n';
        }
    }

// Move here
    playerMove(Direction::Left);
    playerMove(Direction::Right);
    playerMove(Direction::Right);
    playerMove(Direction::Down);
    playerMove(Direction::Down);
    playerMove(Direction::Up);


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
    playerMove(new_coord);
}

void PlayerController::playerMove(Coordinate coord) {
    if (canMove(coord))
        _player.setCoordinate(coord);
}

void PlayerController::playerMove(int x, int y) {
    playerMove({x, y});
}

void PlayerController::changeField(Field &field) {
    _field = field;
}

bool PlayerController::canMove(int x, int y) {
    if (!_field.validateCoordinate(x, y))
        return false;
    return !_field.getFieldCeil(x, y).isOccupied();
}

bool PlayerController::canMove(Coordinate coord) {
    return canMove(coord.x, coord.y);
}

