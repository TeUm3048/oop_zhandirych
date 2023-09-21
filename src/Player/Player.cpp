#include <stdexcept>
#include <utility>
#include "Player.h"

Player::Player() {
    this->name = "<UNKNOWN_PLAYER>";

    this->HP = 100;
}

Player::Player(std::string name) {
    this->setName(std::move(name));


    this->HP = 100;
}

Player::~Player() {
}

void Player::setName(std::string name) {
    if (name.length() < 4 || name.length() > 30) {
        throw std::invalid_argument("The name should be no shorter than 4 characters"
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