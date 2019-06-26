// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "customer.h"

Customer::Customer(long id, string name) : id(id), name(name)
{
    // Constructor
}

Customer::~Customer()
{
    // Destructor
}

void Customer::addTravel(Travel *travel)
{
    travelList.push_back(travel);
}

long Customer::getId() const
{
    return id;
}

size_t Customer::countTravelList() const
{
    return travelList.size();
}

string Customer::getName() const
{
    return name;
}
