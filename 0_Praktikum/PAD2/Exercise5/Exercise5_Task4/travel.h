// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef TRAVEL_H
#define TRAVEL_H

#include <iostream>
#include <vector>
#include <booking.h>
#include <flightbooking.h>
#include <hotelbooking.h>
using namespace std;

class Travel
{
public:
    Travel(long id, long customerId);
    ~Travel();
    void addBooking(Booking* booking);
    long getId() const;
    long getCustomerId() const;
    size_t countTravelBookings() const;
    bool checkRoundtrip();
    bool checkNeedlessHotel();
    bool checkMissingHotel();

private:
    long id, customerId;
    vector <Booking*> travelBookings;
};

#endif // TRAVEL_H
