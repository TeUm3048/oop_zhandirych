//
// Created by TeUm3 on 16.10.2023.
//

#include "TrapEvent.h"

TrapEvent::TrapEvent(unsigned int damage_) : damage(damage_) {

}

void TrapEvent::handle(EventTarget &eventTarget) {
    eventTarget.controller.playerDecreaseHP(damage);
}

IEvent *TrapEvent::clone() {
    return new TrapEvent(*this);
}