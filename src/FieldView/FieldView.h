//
// Created by TeUm3 on 17.10.2023.
//

#ifndef OOP_FIELDVIEW_H
#define OOP_FIELDVIEW_H


#include "../Field/Field.h"
#include "../IObserver/IObserver.h"
#include "../Player/Player.h"

class FieldView : public IObserver, public Observable {
public:
    explicit FieldView(Field &field, Player &player);

    std::string renderCell(FieldCell &cell);

    std::string renderField();

    void update() override;

    const std::string &getFieldString();

private:
    Field &field;
    Player &player;
    std::string field_str_view;
};


#endif //OOP_FIELDVIEW_H
