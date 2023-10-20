//
// Created by TeUm3 on 18.10.2023.
//

#ifndef OOP_EVENTFACTORY_H
#define OOP_EVENTFACTORY_H


#include "../Events/IEvent/IEvent.h"
#include "../Events/HealEvent/HealEvent.h"
#include "../Events/TeleportEvent/TeleportEvent.h"
#include "../Events/TrapEvent/TrapEvent.h"


class EventFactory {
public:
    IEvent *createHealEvent(unsigned healHP);

    IEvent *createTeleportEvent(Coordinate teleportCoordinate);
    IEvent *createTeleportEvent(int x, int y);


    IEvent *createTrapEvent(unsigned damage);
};


#endif //OOP_EVENTFACTORY_H
