#ifndef OOP_OBSERVABLE_H
#define OOP_OBSERVABLE_H


#include <vector>
#include "../Observer/Observer.h"

class Observable {
public:
// Add an observer to the list of Observers for this Observable object.
    void addObserver(Observer *observer);


// The `notifyUpdate()` function is used to notify all the Observers that an update has occurred.
// This function will run `update()` method on each Observer,
// which added for this Observable object.
    void notifyUpdate();

private:
    std::vector<Observer *> _observers;
};


#endif //OOP_OBSERVABLE_H
