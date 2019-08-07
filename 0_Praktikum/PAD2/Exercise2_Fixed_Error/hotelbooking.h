#pragma once
#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H
//#include <iostream>
#include "booking.h"
//using namespace std;

class HotelBooking : public Booking
{
private:

    string hotel;
    string town;
public:
    HotelBooking();
    string getHotel() const;
    void setHotel(const string &value);
    string getTown() const;
    void setTown(const string &value);
};

#endif // HOTELBOOKING_H
