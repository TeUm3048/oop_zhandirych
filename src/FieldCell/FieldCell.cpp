//
// Created by TeUm3 on 08.10.2023.
//

#include "FieldCell.h"

FieldCell::FieldCell(bool occupied_) {
    occupied = occupied_;
}

// this_cell = other;
FieldCell &FieldCell::operator=(const FieldCell &other) {
    if (this == &other) {
        return *this;
    }
    this->occupied = other.occupied;
    return *this;
}

// new_field_cell = FieldCell(old_cell);
FieldCell::FieldCell(const FieldCell &other) {
    this->occupied = other.occupied;
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

