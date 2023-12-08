//
// Created by TeUm3 on 01.12.2023.
//

#include <iostream>
#include "LevelView.h"

LevelView::LevelView(FieldView &fieldView_, PlayerView &playerView_)
        : fieldView(fieldView_), playerView(playerView_) {
    fieldView.addObserver(this);
    playerView.addObserver(this);
}

void LevelView::showLevel() {
    system("cls");
    std::cout << playerView.getPlayerString();
    std::cout << fieldView.getFieldString();
}

void LevelView::renderLevel() {
    playerView.update();
    fieldView.update();
}

void LevelView::update() {
    showLevel();
}

