#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <vector>
#include "travel.h"
//#include "travelagency.h"
using namespace std;

class Customer{
private:
    //Travel *trvl;
    long id;
    string name;
    vector <Travel*> travelList;
public:
    Customer();
    long getId() const;
    void setId(long value);
    string getName() const;
    void setName(const string &value);
};

#endif // CUSTOMER_H
