#include "Observable.h"

void Observable::addObserver(Observer *observer) {
    {
        this->_observers.push_back(observer);
    }
}

void Observable::notifyUpdate() {
    size_t size = this->_observers.size();
    for (size_t i = 0; i < size; i++) {
        this->_observers[i]->update();
    }
}