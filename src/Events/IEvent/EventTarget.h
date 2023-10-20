//
// Created by TeUm3 on 16.10.2023.
//

#ifndef OOP_EVENTTARGET_H
#define OOP_EVENTTARGET_H

#include "../../PlayerController/PlayerController.h"
#include "../../Player/Player.h"
#include "../../Field/Field.h"
#include "../../Coordinate/Coordinate.h"

struct EventTarget {
    PlayerController &controller;
    Player &player;
    Field &field;
    Coordinate coord;
};

#endif //OOP_EVENTTARGET_H
