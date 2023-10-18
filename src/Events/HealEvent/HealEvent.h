//
// Created by TeUm3 on 15.10.2023.
//

#ifndef OOP_HEALEVENT_H
#define OOP_HEALEVENT_H


#include "../IEvent/IEvent.h"
#include "../IEvent/EventTarget.h"

class HealEvent : public IEvent {
public:
    explicit HealEvent(unsigned healHP);


    void handle(EventTarget &) override;

    IEvent *clone() override;

private:
    unsigned heal_hp;
};


#endif //OOP_HEALEVENT_H
