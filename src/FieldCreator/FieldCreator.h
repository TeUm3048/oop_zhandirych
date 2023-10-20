//
// Created by TeUm3 on 16.10.2023.
//

#ifndef OOP_FIELDCREATOR_H
#define OOP_FIELDCREATOR_H

#include "../Field/Field.h"

class FieldCreator {
public:
    Field createFieldForLevel(int level);

private:
    Field createFieldForLevel1();

    Field createFieldForLevel2();
};


#endif //OOP_FIELDCREATOR_H
