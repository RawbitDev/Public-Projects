#pragma once
#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H
//#include <iostream>
#include "booking.h"
//using namespace std;

class FlightBooking : public Booking
{
private:
    string fromDest;
    string toDest;
    string airline;
public:
    FlightBooking();
    string getFromDest() const;
    void setFromDest(const string &value);
    string getToDest() const;
    void setToDest(const string &value);
    string getAirline() const;
    void setAirline(const string &value);
};

#endif // FLIGHTBOOKING_H
