
#ifndef OOP_PLAYERVIEW_H
#define OOP_PLAYERVIEW_H


#include "../Observer/Observer.h"
#include "../Player/Player.h"

class PlayerView : Observer {
private:
    Player *_player;

public:
    PlayerView(Player *player);

    ~PlayerView();

    virtual void update();
};


#endif //OOP_PLAYERVIEW_H
