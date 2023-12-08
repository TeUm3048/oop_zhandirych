//
// Created by TeUm3 on 17.11.2023.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H


#include <stdexcept>
#include <iostream>
#include <conio.h>
#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../PlayerView/PlayerView.h"
#include "../PlayerController/PlayerController.h"
#include "../FieldCreator/FieldCreator.h"
#include "../KeyboardInput/KeyboardInput.h"
#include "../FieldView/FieldView.h"
#include "../LevelView/LevelView.h"

class Game {
public:
    explicit Game(IInput *input);

    void startGame();

    void switchLevel(int level_);

    int level;
    bool win;
    bool loose;
    Player player;
    Field field;
    PlayerView playerView;
    PlayerController controller;
    FieldCreator fieldCreator;
    IInput *input;
    FieldView fieldView;
    LevelView levelView;
private:


    void runControlPlayer();

    bool isLoose();

    bool isWin();

    void endGame() const;
};


#endif //OOP_GAME_H
