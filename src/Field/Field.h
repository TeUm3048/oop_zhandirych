//
// Created by TeUm3 on 08.10.2023.
//

#ifndef OOP_FIELD_H
#define OOP_FIELD_H


#include "../FieldCell/FieldCell.h"
#include "../Coordinate/Coordinate.h"
#include "../Observable/Observable.h"

#define DEFAULT_WIDTH 30
#define DEFAULT_HEIGHT 20
#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define DEFAULT_START {0, 0}
#define DEFAULT_FINISH {19, 18}

class Field : public Observable {
private:
    unsigned width;
    unsigned height;
    Coordinate start{}, finish{};
    FieldCell **field;

public:
    explicit Field(unsigned width = DEFAULT_WIDTH,
                   unsigned height = DEFAULT_HEIGHT,
                   Coordinate start = DEFAULT_START,
                   Coordinate finish = DEFAULT_FINISH
    );

    ~Field();

    Field(const Field &other);

    Field &operator=(const Field &other);

    Field(Field &&other) noexcept;

    Field &operator=(Field &&other) noexcept;

    void swap(Field &other) noexcept;

    [[nodiscard]] unsigned getWidth() const;

    [[nodiscard]] unsigned getHeight() const;

    [[nodiscard]] static bool validateSize(unsigned width_, unsigned height_);

    [[nodiscard]] bool validateCoordinate(int x, int y) const;

    [[nodiscard]] bool validateCoordinate(Coordinate
                                          coord) const;

    [[nodiscard]] FieldCell &getFieldCell(Coordinate coord);

    [[nodiscard]] FieldCell &getFieldCell(int x, int y);

    [[nodiscard]] Coordinate getStart();

    [[nodiscard]] Coordinate getFinish();

    void setEvent(Coordinate coord, IEvent *event);

};


#endif //OOP_FIELD_H
