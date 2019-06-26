// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <travel.h>
using namespace std;

class Customer
{
public:
    Customer(long id, string name);
    ~Customer();
    void addTravel(Travel* travel);
    long getId() const;
    string getName() const;
    size_t countTravelList() const;

private:
    long id;
    string name;
    vector <Travel*> travelList;
};

#endif // CUSTOMER_H
