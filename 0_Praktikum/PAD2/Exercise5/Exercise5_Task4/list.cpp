// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "list.h"

List::List() : root(nullptr)
{
    FlightBooking* dummy = new FlightBooking(0, 0.0, "end", "end", 0, "end", "end", "end", 'E'); // Just a dummy booking for the end
    end = new Node(dummy);
    cursor = end;
}

void List::insertNode(Booking *data)
{
    Node* node = new Node(data); // Create new node
    cursor = end;

    while (cursor->getPreviousNode()) { // Search the position to insert
        if (data->getId() > cursor->getPreviousNode()->getData()->getId())
            break;
        cursor = cursor->getPreviousNode();
    }

    if (root == nullptr) { // If list is empty
        root = node;
        node->setNextNode(end);
        end->setPreviousNode(node);
    } else {
        node->setNextNode(cursor);
        node->setPreviousNode(cursor->getPreviousNode());
        if (cursor->getPreviousNode())
            cursor->getPreviousNode()->setNextNode(node);
        cursor->setPreviousNode(node);
    }
    cursor = node;
    if (cursor->getPreviousNode() == nullptr) // If new node is the first of the list
        root = cursor;
}

void List::deleteNode()
{
    Node* tmpPrevious;
    Node* tmpNext;

    if (root) { // Check if list is not empty
        if (cursor->getPreviousNode() == nullptr) {
            if (cursor->getNextNode() == nullptr) { // If list got only one node
                // Reset the list
                delete cursor;
                root = nullptr;
                end->setPreviousNode(nullptr);
                cursor = end;
            } else { // If user wants to delete root
                cursor = cursor->getNextNode();
                delete (root);
                cursor->setPreviousNode(nullptr);
                root = cursor;
            }
        } else {
            if (cursor->getNextNode() == end) { // If user wants to delete end
                tmpPrevious = cursor->getPreviousNode();
                delete cursor;
                cursor = end;
                end->setPreviousNode(tmpPrevious);
                tmpPrevious->setNextNode(end);
            } else { // Any other node
                tmpPrevious = cursor->getPreviousNode();
                tmpNext = cursor->getNextNode();
                delete cursor;
                tmpPrevious->setNextNode(tmpNext);
                tmpNext->setPreviousNode(tmpPrevious);
                cursor = tmpNext;
            }
        }
    } else {
        throw underflow_error("Cannot delete node. List is already empty!");
    }
    return;
}

void List::step_back()
{
    if (cursor && cursor->getPreviousNode()) // Check if cursor already at the beginning
        cursor = cursor->getPreviousNode(); // Set the cursor to the previous Node
    else
        throw out_of_range("Cannot step back. List is already at the root!");
}

void List::step_forward()
{
    if (cursor && cursor->getNextNode() && cursor->getNextNode() != end) // Check if cursor already at the end
        cursor = cursor->getNextNode(); // Set the cursor to the next Node
    else
        throw out_of_range("Cannot step forword. List is already at the end!");
}

bool List::isAtEnd()
{
    return (cursor == end); // Check if cursor at the end
}

void List::reset()
{
    cursor = root; // Set cursor to root
}

Booking* List::operator[](unsigned int pos)
{
    return this->at(pos);
}

void List::push_back(Booking *data)
{
    this->insertNode(data);
}

Booking* List::at(unsigned int pos)
{
    unsigned int i;
    try {
        this->reset();
        for(i=0; i<pos; i++)
            this->step_forward();
        return this->getNode();
    } catch (out_of_range &e) {
        throw out_of_range(string(e.what()) + " Tried accessing " + to_string(pos) + " but last accessible element is " + to_string(i) + ".");
    }
}

unsigned int List::size()
{
    unsigned int count=0;
    if (root) {
        count++;
        this->reset();
        while(!this->isAtEnd() && cursor->getNextNode() != end) {
            count++;
            this->step_forward();
        }
    }
    return count;

}

Booking *List::getNode()
{
    return cursor->getData();
}
