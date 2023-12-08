//
// Created by TeUm3 on 15.10.2023.
//

#include <stdexcept>
#include "HealEvent.h"

HealEvent::HealEvent(unsigned int heal_hp_, unsigned numberOfUses_) : heal_hp(
        heal_hp_), numberOfUses(numberOfUses_) {
    if (numberOfUses <= 0) {
        throw std::invalid_argument("Invalid numberOfUsage:"
                                    "numberOfUsage must be more than 0");
    }
}

void HealEvent::handle(EventTarget &eventTarget) {
    eventTarget.controller.playerIncreaseHP(heal_hp);
    --numberOfUses;
    if (numberOfUses == 0)
        eventTarget.field.setEvent(eventTarget.coord, nullptr);
}

IEvent *HealEvent::clone() {
    return new HealEvent(*this);
}
