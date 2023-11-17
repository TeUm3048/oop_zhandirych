//
// Created by TeUm3 on 17.11.2023.
//

#include "Game.h"

Game::Game() : level(1), win(false), loose(false), view(player),
               controller(player, field),
               fieldView(field, player) {}


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
//    IInput *input = nullptr;
    try {
        input = new KeyboardInput("../input.txt");
    } catch (std::runtime_error &e) {
        std::cout << e.what();
        return;
    }
    if (input == nullptr)
        return;
//    Field field;
//    Player player;
//    PlayerController controller(player, field);
//    FieldView fieldView(field, player);
//    FieldView fieldView(field, player);
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
//        system("cls");
        std::cout << fieldView.renderField();

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
