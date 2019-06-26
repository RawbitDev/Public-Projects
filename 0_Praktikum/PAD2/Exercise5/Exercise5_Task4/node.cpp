// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "node.h"

Node::Node(Booking *data) : data(data), previousNode(nullptr), nextNode(nullptr)
{
    // Constructor
}

Booking* Node::getData() const
{
    return data;
}

void Node::setData(Booking *value)
{
    data = value;
}

Node *Node::getPreviousNode() const
{
    return previousNode;
}

void Node::setPreviousNode(Node *value)
{
    previousNode = value;
}

Node *Node::getNextNode() const
{
    return nextNode;
}

void Node::setNextNode(Node *value)
{
    nextNode = value;
}
