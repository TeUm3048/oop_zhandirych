

#include <cstdlib>
#include <iostream>
#include "PlayerView.h"

PlayerView::PlayerView(Player &player) : _player(player) {
    _player.addObserver(this);
}

PlayerView::~PlayerView() = default;

std::string PlayerView::renderPlayer() {
    std::string buffer = "Player: " + _player.getName() + "\n" +
                         "Player position:" + "\n" +
                         "\t X:" + std::to_string(_player.getX()) + "\n" +
                         "\t Y:" + std::to_string(_player.getY()) + "\n" +
                         "HP: " + std::to_string(_player.getHP()) + "\n";
    return buffer;
}

void PlayerView::update() {
    player_str_view = renderPlayer();
    this->notifyUpdate();
}

const std::string &PlayerView::getPlayerString() {
    return player_str_view;
}
