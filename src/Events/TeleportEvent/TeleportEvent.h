//
// Created by TeUm3 on 16.10.2023.
//

#ifndef OOP_TELEPORTEVENT_H
#define OOP_TELEPORTEVENT_H


#include "../IEvent/EventTarget.h"

class TeleportEvent : public IEvent {
public:
    explicit TeleportEvent(Coordinate teleportCoordinate);

    explicit TeleportEvent(int x, int y);

    void handle(EventTarget &eventTarget) override;

    IEvent *clone() override;


private:
    Coordinate tpCoord;
};


#endif //OOP_TELEPORTEVENT_H
