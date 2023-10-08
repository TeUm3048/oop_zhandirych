//
// Created by TeUm3 on 08.10.2023.
//

#ifndef OOP_FIELDCELL_H
#define OOP_FIELDCELL_H


#include "../Event/Event.h"

class FieldCell {
private:
    bool occupied;
    Event *event;
public:

    explicit FieldCell(bool occupied_ = false);

    FieldCell(const FieldCell &other);

    FieldCell &operator=(const FieldCell &other);

    Event *getEvent();

    void addEvent(Event *event);

    void removeOccupied();

    void setOccupied();

    [[nodiscard]] bool isOccupied() const;

};


#endif //OOP_FIELDCELL_H
