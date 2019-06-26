// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include <iostream>
#include <booking.h>
using namespace std;

class HotelBooking : public Booking
{
public:
    HotelBooking(long id, double price, string fromDate, string toDate, long travelId, string hotel, string town, bool smoke);
    ~HotelBooking();
    virtual string showDetails();
    string getHotel() const;
    string getTown() const;
    bool isSmoke() const;

private:
    string hotel, town;
    bool smoke;
};

#endif // HOTELBOOKING_H
