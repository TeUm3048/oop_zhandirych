//
// Created by TeUm3 on 15.10.2023.
//

#include "HealEvent.h"

HealEvent::HealEvent(unsigned int heal_hp_) : heal_hp(heal_hp_) {
}

void HealEvent::handle(EventTarget &eventTarget) {
    eventTarget.controller.playerIncreaseHP(heal_hp);
}

IEvent *HealEvent::clone() {
    return new HealEvent(*this);
}
