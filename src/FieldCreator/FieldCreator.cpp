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
        field.getFieldCeil(x, y).setOccupied();
    }
    y = 2;
    for (x = 0; x < field.getWidth() - 5; ++x) {
        field.getFieldCeil(x, y).setOccupied();
    }
    x = field.getWidth() - 6;
    for (y = 0; y < 3; ++y) {
        field.getFieldCeil(x, y).setOccupied();
    }

    for (y = 4; y < field.getHeight(); ++y) {
        field.getFieldCeil(x, y).setOccupied();
    }


    return field;
}

Field FieldCreator::createFieldForLevel2() {
    Field field = Field(DEFAULT_WIDTH, DEFAULT_HEIGHT, {1, 2},
                        DEFAULT_FINISH);
    for (int i = 0; i < std::min(field.getWidth(), field.getHeight()); ++i) {
        FieldCell &cell = field.getFieldCeil(i, i);
        FieldCell &right_cell = field.getFieldCeil(i + 1, i);
        cell.setOccupied();
        EventFactory eventFactory;
        IEvent *tpEv = eventFactory.createTeleportEvent(3, 2);
        field.getFieldCeil(2, 3).setEvent(tpEv);

        IEvent *healEv = eventFactory.createHealEvent(30);
        IEvent *trapEv = eventFactory.createTrapEvent(21);
        field.getFieldCeil(4, 2).setEvent(healEv);
        field.getFieldCeil(3, 1).setEvent(trapEv);
    }
    return field;
}