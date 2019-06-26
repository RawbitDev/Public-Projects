// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef NODE_H
#define NODE_H

#include <booking.h>
using namespace std;

class Node
{
public:
    Node(Booking *data);
    void setData(Booking *value);
    void setPreviousNode(Node *value);
    void setNextNode(Node *value);
    Booking *getData() const;
    Node *getPreviousNode() const;
    Node *getNextNode() const;

private:
    Booking *data;
    Node *previousNode;
    Node *nextNode;
};

#endif // NODE_H
