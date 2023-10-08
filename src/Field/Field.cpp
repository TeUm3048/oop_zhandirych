//
// Created by TeUm3 on 08.10.2023.
//

#include <stdexcept>
#include "Field.h"

Field::Field(unsigned int width_, unsigned int height_) {
    if (!validateSize(width_, height_))
        throw std::invalid_argument("Field of invalid size");
    width = width_;
    height = height_;
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

FieldCell Field::getFieldCeil(Coordinate coord) {
    return field[coord.x][coord.y];
}

FieldCell Field::getFieldCeil(int x, int y) {
    return getFieldCeil({x, y});
}

Coordinate Field::getStart() {
    return start;
}

Coordinate Field::getFinish() {
    return finish;
}
