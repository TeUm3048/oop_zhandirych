//
// Created by TeUm3 on 08.10.2023.
//

#ifndef OOP_EVENT_H
#define OOP_EVENT_H


#include "../Player/Player.h"

class Event {
    void virtual handle(Player &player) = 0;
};


#endif //OOP_EVENT_H
