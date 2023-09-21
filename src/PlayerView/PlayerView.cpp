

#include <cstdlib>
#include <iostream>
#include "PlayerView.h"
#include "../Player/Player.h"

PlayerView::PlayerView(Player *player) {
    this->_player = player;
    this->_player->addObserver(this);
}

PlayerView::~PlayerView() {
}

void PlayerView::update() {
    system("cls");
    std::cout << "Player: " << _player->getName() << "\n";
    std::cout << "HP: " << _player->getHP() << "\n";
    std::cout << "Enter new HP: ";
}