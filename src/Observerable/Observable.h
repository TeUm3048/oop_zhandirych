#ifndef OOP_OBSERVABLE_H
#define OOP_OBSERVABLE_H


#include <vector>
#include "../Observer/Observer.h"

class Observable {
public:
    void addObserver(Observer *observer);

    void notifyUpdate();

private:
    std::vector<Observer *> _observers;
};


#endif //OOP_OBSERVABLE_H
