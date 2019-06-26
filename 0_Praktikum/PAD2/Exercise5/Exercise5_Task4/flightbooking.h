// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include <iostream>
#include <booking.h>
using namespace std;

class FlightBooking : public Booking
{
public:
    FlightBooking(long id, double price, string fromDate, string toDate, long travelId, string fromDest, string toDest, string airline, char seatPref);
    ~FlightBooking();
    virtual string showDetails();
    string getAirline() const;
    string getFromDest() const;
    string getToDest() const;

private:
    string fromDest, toDest, airline;
    char seatPref;
};

#endif // FLIGHTBOOKING_H
