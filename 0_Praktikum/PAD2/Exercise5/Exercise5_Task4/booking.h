// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
using namespace std;

class Booking
{
public:
    Booking(long id, double price, string fromDate, string toDate, long travelId);
    virtual ~Booking() = 0;
    long getId() const;
    long getTravelId() const;
    double getPrice() const;
    string getFromDate() const;
    string getToDate() const;
    virtual string showDetails();

protected:
    long id, travelId;
    double price;
    string fromDate, toDate;
};

#endif // BOOKING_H
