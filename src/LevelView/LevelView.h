//
// Created by TeUm3 on 01.12.2023.
//

#ifndef OOP_LEVELVIEW_H
#define OOP_LEVELVIEW_H


#include "../IObserver/IObserver.h"
#include "../FieldView/FieldView.h"
#include "../PlayerView/PlayerView.h"

class LevelView : public IObserver {
private:
    FieldView &fieldView;
    PlayerView &playerView;
public:
    LevelView(FieldView &fieldView_, PlayerView &playerView_);

    void showLevel();

    void update() override;

    void renderLevel();
};


#endif //OOP_LEVELVIEW_H
