//
// Created by TeUm3 on 16.10.2023.
//

#include "TeleportEvent.h"

TeleportEvent::TeleportEvent(Coordinate teleportCoordinate) : tpCoord(
        teleportCoordinate) {
}

TeleportEvent::TeleportEvent(int x, int y) : TeleportEvent(Coordinate{x, y}) {
}

void TeleportEvent::handle(EventTarget &eventTarget) {
    eventTarget.controller.playerMove(tpCoord);

}

IEvent *TeleportEvent::clone() {
    return new TeleportEvent(*this);
}

