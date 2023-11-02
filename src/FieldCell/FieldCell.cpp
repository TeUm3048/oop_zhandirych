//
// Created by TeUm3 on 08.10.2023.
//

#include <utility>
#include "FieldCell.h"

FieldCell::FieldCell(bool occupied_, IEvent *event_) : event(event_) {
    occupied = occupied_;
}

FieldCell::~FieldCell() {
    delete event;
}

// FieldCell new_field_cell(other);
FieldCell::FieldCell(const FieldCell &other) {
    event = other.event ? other.event->clone() : nullptr;
    occupied = other.occupied;
}

// this_cell = other;
FieldCell &FieldCell::operator=(const FieldCell &other) {
    if (this == &other)
        return *this;
    FieldCell tmp(other);
    this->swap(tmp);
    return *this;
}

FieldCell::FieldCell(FieldCell &&other) noexcept: occupied(false),
                                                  event(nullptr) {
    this->swap(other);
}

// field_cell = std::move(other)
FieldCell &FieldCell::operator=(FieldCell &&other) noexcept {
    this->swap(other);
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

IEvent *FieldCell::getEvent() {
    return event;
}

void FieldCell::setEvent(IEvent *event_) {
    delete event;
    event = event_;
}

void FieldCell::swap(FieldCell &other) noexcept {
    std::swap(this->occupied, other.occupied);
    std::swap(this->event, other.event);

}
