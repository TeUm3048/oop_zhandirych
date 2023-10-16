//
// Created by TeUm3 on 08.10.2023.
//

#ifndef OOP_IEVENT_H
#define OOP_IEVENT_H


class EventTarget;


class IEvent {
public:
    virtual void handle(EventTarget &) = 0;

    virtual IEvent *clone() = 0;

};


#endif //OOP_IEVENT_H
