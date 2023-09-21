#ifndef OOP_PLAYERCONTROLLER_H
#define OOP_PLAYERCONTROLLER_H


#include "../Player/Player.h"

class PlayerController {
public:
    PlayerController(Player *player);

    ~PlayerController();

    void start();

private:
    Player *_player;
};


#endif //OOP_PLAYERCONTROLLER_H
