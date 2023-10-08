#ifndef OOP_PLAYERCONTROLLER_H
#define OOP_PLAYERCONTROLLER_H

#include "../Player/Player.h"
#include "../Field/Field.h"

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

    explicit PlayerController(Player &player, Field &field);

    ~PlayerController();

    void start();

    void changeField(Field &field);

protected:
    void playerMove(Direction direction);

    [[nodiscard]] bool canMove(int x, int y);

    [[nodiscard]] bool canMove(Coordinate coord);

private:
    Player &_player;
    Field _field;

};

#endif //OOP_PLAYERCONTROLLER_H
