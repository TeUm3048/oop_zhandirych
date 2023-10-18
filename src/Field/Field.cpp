//
// Created by TeUm3 on 08.10.2023.
//

#include <stdexcept>
#include <utility>
#include "Field.h"

Field::Field(unsigned int width_, unsigned int height_, Coordinate start_,
             Coordinate finish_) {
    if (!validateSize(width_, height_))
        throw std::invalid_argument("Field of invalid size");
    width = width_;
    height = height_;

    if (!validateCoordinate(start_))
        throw std::invalid_argument("Invalid start_ coordinate");
    if (!validateCoordinate(finish_))
        throw std::invalid_argument("Invalid finish_ coordinate");

    start = start_;
    finish = finish_;
    field = new FieldCell *[width];
    for (int i = 0; i < width; i++) {
        field[i] = new FieldCell[height];
    }

}

Field::~Field() {
    for (int i = 0; i < width; i++) {
        delete[] field[i];
    }
    delete[] field;
}

// copy constructor
Field::Field(const Field &other) : width(other.width), height(other.height),
                                   start(other.start), finish(other.finish) {
    field = new FieldCell *[width];
    for (int i = 0; i < width; ++i) {
        field[i] = new FieldCell[height];
        std::copy(other.field[i], other.field[i] + height, field[i]);
    }
}

// copy assigment
Field &Field::operator=(const Field &other) {
    if (this == &other)
        return *this;
    if (width != other.width) {
        delete field;
        field = new FieldCell *[other.width];
        for (int i = 0; i < other.width; i++) {
            field[i] = new FieldCell[other.height];
        }
    } else if (height != other.height) {
        for (int i = 0; i < other.width; i++) {
            delete field[i];
            field[i] = new FieldCell[other.height];
        }
    }

    width = other.width;
    height = other.height;
    start = other.start;
    finish = other.finish;
    for (int i = 0; i < width; ++i) {
        std::copy(other.field[i], other.field[i] + height, field[i]);
    }
    return *this;
}

// move assigment
Field &Field::operator=(Field &&other) noexcept {
    if (this == &other)
        return *this;
    delete field;
    height = other.height;
    width = other.width;
    start = other.start;
    finish = other.finish;
    field = std::exchange(other.field, nullptr);
    return *this;
}

bool Field::validateCoordinate(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;

}

bool Field::validateCoordinate(Coordinate coord) const {
    return validateCoordinate(coord.x, coord.y);
}

bool Field::validateSize(unsigned int width_, unsigned int height_) {
    return width_ >= 1 && width_ <= MAX_WIDTH &&
           height_ >= 1 && height_ <= MAX_HEIGHT;
}

unsigned Field::getWidth() const {
    return width;
}

unsigned Field::getHeight() const {
    return height;
}

FieldCell& Field::getFieldCeil(Coordinate coord) {
    if (!validateCoordinate(coord))
        throw std::invalid_argument("Invalid ceil coordinate");
    return field[coord.x][coord.y];
}

FieldCell& Field::getFieldCeil(int x, int y) {
    return getFieldCeil({x, y});
}

Coordinate Field::getStart() {
    return start;
}

Coordinate Field::getFinish() {
    return finish;
}
