//
// Created by TeUm3 on 17.10.2023.
//

#include <iostream>
#include "FieldView.h"
#include "../Events/HealEvent/HealEvent.h"
#include "../Events/TrapEvent/TrapEvent.h"
#include "../Events/TeleportEvent/TeleportEvent.h"


FieldView::FieldView(Field &field_, Player &player_) : field(field_),
                                                       player(player_) {
    field.addObserver(this);
    player.addObserver(this);
}

std::string FieldView::renderCell(FieldCell &cell) {
    IEvent *event = cell.getEvent();
    if (auto *heal = dynamic_cast<HealEvent *>(event))
        return "[+]";
    if (auto *trap = dynamic_cast<TrapEvent *>(event))
        return "[.]";
    if (auto *tp = dynamic_cast<TeleportEvent *>(event))
        return "[0]";
    if (cell.isOccupied())
        return "[X]";
    return "[ ]";
}

std::string FieldView::renderField() {
    std::string buff;

    int render_lenght = 13;

    Coordinate start_render = {0, 0};
    Coordinate end_render = {static_cast<int>(field.getWidth()),
                             static_cast<int>(field.getHeight())};
    // Set player to center
    // Field 13x13 r=6
    int r = render_lenght / 2;
    Coordinate playerCoordinate = player.getCoordinate();
    if (field.getWidth() > render_lenght) {
        if (playerCoordinate.x < r) {
            start_render.x = 0;
            end_render.x = render_lenght;

        } else if (playerCoordinate.x < end_render.x - r) {
            start_render.x = playerCoordinate.x - r;
            end_render.x = playerCoordinate.x + r + 1;
        } else if (playerCoordinate.x >= end_render.x - r) {
            start_render.x = end_render.x - render_lenght;
        }
    }
    if (field.getWidth() > render_lenght) {
        if (playerCoordinate.y < r) {
            start_render.y = 0;
            end_render.y = render_lenght;

        } else if (playerCoordinate.y < end_render.y - r) {
            start_render.y = playerCoordinate.y - r;
            end_render.y = playerCoordinate.y + r + 1;
        } else if (playerCoordinate.y >= end_render.y - r) {
            start_render.y = end_render.y - render_lenght;
        }
    }


    // Generate field
    for (int y = end_render.y - 1; y >= start_render.y; --y) {
        for (int x = start_render.x; x < end_render.x; ++x) {
            // Up to down
            if (player.getX() == x && player.getY() == y) {
                buff += "[P]";
            } else {
                FieldCell cell = field.getFieldCell(x, y);
                buff += renderCell(cell);
            }
        }
        buff += '\n';
    }
    return buff;
}

void FieldView::update() {
    field_str_view = renderField();
    this->notifyUpdate();
}

const std::string &FieldView::getFieldString() {
    return field_str_view;
}
