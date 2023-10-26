#include <iostream>
#include "PlayerController.h"
#include "../FieldView/FieldView.h"
#include "../Events/IEvent/EventTarget.h"

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

    playerMove(_field.getStart());


    FieldView fieldView(_field, _player);
    unsigned temp = 0;
    do {
        std::cout << fieldView.renderField();

        std::cout << "Enter direction: ";
        char buff;
        std::cin >> buff;

        switch (buff) {
            case 'W':
            case 'w':
                playerMove(Up);
                break;
            case 'A':
            case 'a':
                playerMove(Left);
                break;
            case 'S':
            case 's':
                playerMove(Down);
                break;
            case 'D':
            case 'd':
                playerMove(Right);
                break;
        }

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
    if (!canMove(coord))
        return;
    _player.setCoordinate(coord);

    triggerEvent(_player.getCoordinate());
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
    return !_field.getFieldCell(x, y).isOccupied();
}

bool PlayerController::canMove(Coordinate coord) {
    return canMove(coord.x, coord.y);
}

void PlayerController::playerDecreaseHP(unsigned int HP) {
    unsigned prevHP = _player.getHP();
    unsigned newHP = prevHP >= HP ? prevHP - HP : 0;
    _player.setHP(newHP);
}

void PlayerController::playerIncreaseHP(unsigned int HP) {
    unsigned prevHP = _player.getHP();
    _player.setHP(prevHP + HP);
}

void PlayerController::triggerEvent(Coordinate coord) {
    IEvent *ev = _field.getFieldCell(coord).getEvent();
    if (ev) {
        EventTarget eventTarget = {*this, _player, _field,
                                   coord};
        ev->handle(eventTarget);
    }
}

void PlayerController::triggerEvent(int x, int y) {
    triggerEvent({x, y});
}

