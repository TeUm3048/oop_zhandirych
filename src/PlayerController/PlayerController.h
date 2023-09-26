#ifndef OOP_PLAYERCONTROLLER_H
#define OOP_PLAYERCONTROLLER_H

#include "../Player/Player.h"

enum Direction {
    Up, Right, Down, Left
};

class PlayerController {
public:

//  The `explicit` keyword is used to prevent implicit conversions.
//  In this case, it is used in the constructor of the `PlayerController` class
//  to prevent implicit conversions from the `Player` class to `PlayerController`.
//  This means that when creating a `PlayerController` object,
//  you must explicitly pass a `Player` object as an argument to the constructor.

    explicit PlayerController(Player &player);

    ~PlayerController();

    void start();

protected:
    void playerMove(Direction direction);

private:
    Player &_player;
};

#endif //OOP_PLAYERCONTROLLER_H
