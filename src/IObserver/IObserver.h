#ifndef OOP_IOBSERVER_H
#define OOP_IOBSERVER_H


class IObserver {
public:
//  The `virtual` keyword is used to declare a virtual function in a base class.
//  A virtual function is a member function that can be overridden
//  in a derived class.
//  When a virtual function is called through a pointer or reference
//  to the base class, the actual function called is determined at runtime
//  based on the type of the object being pointed to or referenced.
//  This allows for dynamic polymorphism, where different derived classes can
//  provide different implementations of the same function.

    virtual void update() = 0;
};


#endif //OOP_IOBSERVER_H
