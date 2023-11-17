//
// Created by TeUm3 on 08.10.2023.
//

#ifndef OOP_COORDINATE_H
#define OOP_COORDINATE_H


struct Coordinate {
    int x;
    int y;

    bool operator==(const Coordinate &other) const {
        return x == other.x && y == other.y;
    };

};


#endif //OOP_COORDINATE_H
