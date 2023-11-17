//
// Created by TeUm3 on 17.11.2023.
//

#ifndef OOP_GAMEMENU_H
#define OOP_GAMEMENU_H


#include "../Game/Game.h"

class GameMenu {
    Game game;
public:

    void start() {
        std::string level;
        std::cout << "Выберите уровень:" << std::endl;
        std::cout << "Чтобы выйти нажмите q" << std::endl;
        std::cin >> level;
        while (level != "q") {
            game.switchLevel(std::stoi(level));
            game.startGame();
            std::cout << "Выберите уровень:" << std::endl;
            std::cout << "Чтобы выйти нажмите q" << std::endl;
            std::cin >> level;

        }
    }

};


#endif //OOP_GAMEMENU_H
