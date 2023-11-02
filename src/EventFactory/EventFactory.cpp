//
// Created by TeUm3 on 18.10.2023.
//

#include <stdexcept>
#include "EventFactory.h"

IEvent *EventFactory::createHealEvent(unsigned healHP,
                                      unsigned numberOfUses) {
    try {
        return new HealEvent(healHP, numberOfUses);
    }
    catch (const std::invalid_argument &e) {
        return nullptr;
    }
}

IEvent *EventFactory::createTeleportEvent(Coordinate teleportCoordinate) {
    return new TeleportEvent(teleportCoordinate);
}

IEvent *EventFactory::createTeleportEvent(int x, int y) {
    return createTeleportEvent({x, y});
}

IEvent *EventFactory::createTrapEvent(unsigned damage) {
    return new TrapEvent(damage);
}
