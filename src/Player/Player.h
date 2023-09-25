#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


#include <string>
#include "../Observable/Observable.h"

class Player : public Observable {
public:
    Player();

    ~Player();

    void setName(std::string name);

    std::string getName();

    void setHP(unsigned HP);

    unsigned getHP() const;

    bool isDead();

    bool isAlive();

    void setX(int x_);

    int getX() const;

    void setY(int y_);

    int getY() const;

private:
    std::string name;
    unsigned HP;
// ? Add the following fields?
//	unsigned EXP;
//	int attack;
//	int defense;
//	unsigned level;
};


#endif //OOP_PLAYER_H
