//
// Created by TeUm3 on 08.10.2023.
//

#include <utility>
#include "FieldCell.h"

FieldCell::FieldCell(bool occupied_, Event *event_) : event(event_) {
    occupied = occupied_;
}

// new_field_cell = FieldCell(old_cell);
FieldCell::FieldCell(const FieldCell &other) {
    delete this;
    event = nullptr;
    occupied = other.occupied;

}


// this_cell = other;
FieldCell &FieldCell::operator=(const FieldCell &other) {
    if (this == &other) {
        return *this;
    }
    this->occupied = other.occupied;
    return *this;
}


// field_cell = std::move(other)
FieldCell &FieldCell::operator=(FieldCell &&other) noexcept {
    occupied = other.occupied;
    event = std::exchange(other.event, nullptr);
    return *this;
}

void FieldCell::removeOccupied() {
    occupied = false;
}

void FieldCell::setOccupied() {
    occupied = true;
}

bool FieldCell::isOccupied() const {
    return occupied;
}

Event &FieldCell::getEvent() {
    return *event;
}


