
#ifndef OOP_PLAYERVIEW_H
#define OOP_PLAYERVIEW_H


#include "../IObserver/IObserver.h"
#include "../Player/Player.h"

class PlayerView : IObserver {
private:
    Player &_player;

public:
    //    The `explicit` keyword is used to prevent implicit conversions.

    explicit PlayerView(Player &player);

    ~PlayerView();

    // The `override` keyword is used to explicitly indicate that a member function
    // is intended to override a virtual function from a base class.
    // It helps to ensure that the function signature in the derived class matches
    // the function signature in the base class, preventing accidental mistakes.
    // If the function in the derived class does not actually override a virtual function in the base class,
    // a compilation error will occur.

    void update() override;

    void renderPlayer();
};


#endif //OOP_PLAYERVIEW_H
