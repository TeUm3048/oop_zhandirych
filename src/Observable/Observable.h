#ifndef OOP_OBSERVABLE_H
#define OOP_OBSERVABLE_H


#include <vector>
#include "../IObserver/IObserver.h"

class Observable {
public:
// Add an observer to the list of Observers for this Observable object.
    void addObserver(IObserver *observer);


// The `notifyUpdate()` function is used to notify all the Observers that an update has occurred.
// This function will run `update()` method on each IObserver,
// which added for this Observable object.
    void notifyUpdate();

private:
    std::vector<IObserver *> _observers;
};


#endif //OOP_OBSERVABLE_H
