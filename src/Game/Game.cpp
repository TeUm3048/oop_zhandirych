//
// Created by TeUm3 on 17.11.2023.
//

#include "Game.h"

Game::Game(IInput *input_) : level(1), win(false), loose(false),
                             playerView(player),
                             controller(player, field),
                             fieldView(field, player), input(input_),
                             levelView(fieldView, playerView) {}


void Game::switchLevel(int level_) {
    level = level_;
    field = fieldCreator.createFieldForLevel(level);
    controller.changeField(field);
}


void Game::startGame() {
    runControlPlayer();
    endGame();
}

void Game::runControlPlayer() {

    if (input == nullptr)
        return;
    levelView.renderLevel();
    levelView.showLevel();

    Controls command = input->read();
    while (Controls::QUIT != command) {
        switch (command) {
            case MOVE_UP:
                controller.playerMove(Direction::Up);
                break;
            case MOVE_RIGHT:
                controller.playerMove(Direction::Right);
                break;
            case MOVE_DOWN:
                controller.playerMove(Direction::Down);
                break;
            case MOVE_LEFT:
                controller.playerMove(Direction::Left);
                break;
            default:
                break;
        }
//        std::cout << fieldView.renderField();

        loose = isLoose();
        if (loose) break;

        win = isWin();
        if (win) break;

        command = input->read();
    }
}

bool Game::isLoose() {
    return player.isDead();
}

bool Game::isWin() {
    return field.getFinish() == player.getCoordinate();
}

void Game::endGame() const {
    if (win) {
        std::cout << "Congratulations! Вы победили!" << std::endl;
        return;
    }
    if (loose) {
        std::cout << "Congratulations! Вы проиграли!" << std::endl;
        return;
    }
}
