#include "Player.h"
#include <stdexcept>

Player::Player() {
    this->name = "<UNKNOWN_PLAYER>";

    this->HP = 100;
}

Player::~Player() {
}

void Player::setName(std::string name) {
    if (name.length() < 4 || name.length() > 30) {
        throw std::invalid_argument(
                "The name should be no shorter than 4 characters"
                "and no longer than 30 characters");
    }

    this->name = name;
    this->notifyUpdate();
}

std::string Player::getName() {
    return this->name;
}

void Player::setHP(unsigned HP) {
    this->HP = HP;
    this->notifyUpdate();
}

unsigned Player::getHP() const {
    return this->HP;
}

bool Player::isDead() {
    return !this->isAlive();
}

bool Player::isAlive() {
    return this->HP > 0;
}


void Player::setX(int x_) {
    coordinate.x = x_;
    this->notifyUpdate();
}

int Player::getX() const {
    return coordinate.x;
}

void Player::setY(int y_) {
    coordinate.y = y_;
    this->notifyUpdate();
}

int Player::getY() const {
    return coordinate.y;
}

void Player::setCoordinate(Coordinate coordinate_) {
    coordinate = coordinate_;
    notifyUpdate();

}

void Player::setCoordinate(int x_, int y_) {
    setCoordinate({x_, y_});
}

Coordinate Player::getCoordinate() {
    return coordinate;
}
