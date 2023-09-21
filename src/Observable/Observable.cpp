#include "Observable.h"

void Observable::addObserver(Observer *observer) {
    {
        this->_observers.push_back(observer);
    }
}

void Observable::notifyUpdate() {
    int size = this->_observers.size();
    for (int i = 0; i < size; i++) {
        this->_observers[i]->update();
    }
}