//
// Created by TeUm3 on 08.10.2023.
//

#ifndef OOP_FIELD_H
#define OOP_FIELD_H


#include "../FieldCell/FieldCell.h"
#include "../Coordinate/Coordinate.h"

#define DEFAULT_WIDTH 30
#define DEFAULT_HEIGHT 20
#define MAX_WIDTH 200
#define MAX_HEIGHT 200

class Field {
private:
    unsigned width;
    unsigned height;
    Coordinate start, finish;
    FieldCell **field;

public:
    explicit Field(unsigned width = DEFAULT_WIDTH,
                   unsigned height = DEFAULT_HEIGHT);

    ~Field();

    unsigned getWidth() const;

    unsigned getHeight() const;

    [[nodiscard]] static bool validateSize(unsigned width_, unsigned height_);

    [[nodiscard]] bool validateCoordinate(int x, int y) const;

    [[nodiscard]] bool validateCoordinate(Coordinate
                                          coord) const;

    FieldCell getFieldCeil(Coordinate coord);

    FieldCell getFieldCeil(int x, int y);

    Coordinate getStart();

    Coordinate getFinish();

};


#endif //OOP_FIELD_H
