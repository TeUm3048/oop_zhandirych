//
// Created by TeUm3 on 08.10.2023.
//

#ifndef OOP_FIELDCELL_H
#define OOP_FIELDCELL_H


#include <memory>
#include "../Events/IEvent/IEvent.h"


class FieldCell {
private:
    bool occupied;
    IEvent *event;
public:

    explicit FieldCell(bool occupied_ = false, IEvent *event_ = nullptr);

    ~FieldCell();

    FieldCell(const FieldCell &other);

    FieldCell &operator=(const FieldCell &other);

    FieldCell(FieldCell &&other) noexcept ;

    FieldCell &operator=(FieldCell &&other) noexcept;

    void removeOccupied();

    void setOccupied();

    [[nodiscard]] bool isOccupied() const;

    IEvent *getEvent();

    void setEvent(IEvent *event);

    void swap(FieldCell &other) noexcept;

};


#endif //OOP_FIELDCELL_H
