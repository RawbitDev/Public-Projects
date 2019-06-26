// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef LIST_H
#define LIST_H

#include <node.h>
#include <booking.h>
#include <flightbooking.h>

class List
{
public:
    List();
    void insertNode(Booking *data);
    Booking *getNode();
    void deleteNode();
    void step_back();
    void step_forward();
    bool isAtEnd();
    void reset();
    Booking* at(unsigned int pos);
    unsigned int size();
    Booking* operator[](unsigned int pos);
    void push_back(Booking *data);

private:
    Node *root;
    Node *cursor;
    Node *end;
};

#endif // LIST_H
