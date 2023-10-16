//
// Created by TeUm3 on 16.10.2023.
//

#ifndef OOP_TRAPEVENT_H
#define OOP_TRAPEVENT_H


#include "../IEvent/IEvent.h"
#include "../IEvent/EventTarget.h"

class TrapEvent : public IEvent {
public:
    explicit TrapEvent(unsigned damage);

    void handle(EventTarget &) override;

    IEvent *clone() override;

private:
    unsigned damage;
};


#endif //OOP_TRAPEVENT_H
