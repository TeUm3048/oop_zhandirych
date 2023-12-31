//
// Created by TeUm3 on 16.10.2023.
//

#include "FieldCreator.h"
#include "../EventFactory/EventFactory.h"

Field FieldCreator::createFieldForLevel(int level) {
    switch (level) {
        case 1:
            return createFieldForLevel1();
            break;
        case 2:
            return createFieldForLevel2();
            break;
        default:
            return Field();
            break;
    }
}

Field FieldCreator::createFieldForLevel1() {
    Field field = Field(DEFAULT_WIDTH, DEFAULT_HEIGHT, {27, 3});
    int x, y;
    y = 4;
    for (x = 0; x < field.getWidth() - 5; ++x) {
        field.getFieldCell(x, y).setOccupied();
    }
    y = 2;
    for (x = 0; x < field.getWidth() - 5; ++x) {
        field.getFieldCell(x, y).setOccupied();
    }
    x = field.getWidth() - 6;
    for (y = 0; y < 3; ++y) {
        field.getFieldCell(x, y).setOccupied();
    }

    for (y = 4; y < field.getHeight(); ++y) {
        field.getFieldCell(x, y).setOccupied();
    }


    return field;
}

Field FieldCreator::createFieldForLevel2() {
    Field field = Field(DEFAULT_WIDTH, DEFAULT_HEIGHT, {1, 2},
                        DEFAULT_FINISH);
    for (int i = 0; i < std::min(field.getWidth(), field.getHeight()); ++i) {
        FieldCell &cell = field.getFieldCell(i, i);
        FieldCell &right_cell = field.getFieldCell(i + 1, i);
        cell.setOccupied();
    }
    IEvent *tpEv = EventFactory::createTeleportEvent(3, 2);
    field.getFieldCell(2, 3).setEvent(tpEv);

    IEvent *healEv = EventFactory::createHealEvent(30);
    IEvent *trapEv = EventFactory::createTrapEvent(21);
    field.getFieldCell(4, 2).setEvent(healEv);
    field.getFieldCell(3, 1).setEvent(trapEv);

    return field;
}