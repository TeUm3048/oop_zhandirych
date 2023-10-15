//
// Created by TeUm3 on 08.10.2023.
//

#ifndef OOP_FIELDCELL_H
#define OOP_FIELDCELL_H


#include <memory>
#include "../Event/Event.h"

class FieldCell {
private:
    bool occupied;
    std::unique_ptr<Event> event;
public:

    explicit FieldCell(bool occupied_ = false, Event *event_ = nullptr);

    FieldCell(const FieldCell &other);


    FieldCell &operator=(const FieldCell &other);

    FieldCell &operator=(FieldCell &&other) noexcept;

    void removeOccupied();

    void setOccupied();

    [[nodiscard]] bool isOccupied() const;

    Event &getEvent();

};


#endif //OOP_FIELDCELL_H
