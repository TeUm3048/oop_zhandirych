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
    static IEvent *createHealEvent(unsigned healHP);

    static IEvent *createTeleportEvent(Coordinate teleportCoordinate);

    static IEvent *createTeleportEvent(int x, int y);


    static IEvent *createTrapEvent(unsigned damage);
};


#endif //OOP_EVENTFACTORY_H
