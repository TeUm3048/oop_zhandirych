#include "Observable.h"

void Observable::addObserver(IObserver *observer) {
    {
        this->_observers.push_back(observer);
    }
}

void Observable::notifyUpdate() {
    std::size_t size = this->_observers.size();
    for (std::size_t i = 0; i < size; i++) {
        this->_observers[i]->update();
    }
}