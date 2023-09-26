

#include <cstdlib>
#include <iostream>
#include "PlayerView.h"

PlayerView::PlayerView(Player &player) : _player(player) {
    _player.addObserver(this);
}

PlayerView::~PlayerView() {
}

void PlayerView::renderPlayer() {
    system("cls");
    std::cout << "Player: " << _player.getName() << std::endl;
    std::cout << "Player position:" << std::endl;
    std::cout << "\t X:" << _player.getX() << std::endl;
    std::cout << "\t Y:" << _player.getY() << std::endl;
    std::cout << "HP: " << _player.getHP() << "\n";
}

void PlayerView::update() {
    PlayerView::renderPlayer();
}