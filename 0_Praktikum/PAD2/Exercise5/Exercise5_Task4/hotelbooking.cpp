// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "hotelbooking.h"

HotelBooking::HotelBooking(long id, double price, string fromDate, string toDate, long travelId, string hotel, string town, bool smoke) : Booking(id, price, fromDate, toDate, travelId), hotel(hotel), town(town), smoke(smoke)
{
    // Constructor
}

HotelBooking::~HotelBooking()
{
    // Destructor
}

string HotelBooking::showDetails()
{
    if (smoke) {return "Raucherzimmer";}
    return "Nichtraucherzimmer";
}

string HotelBooking::getHotel() const
{
    return hotel;
}

string HotelBooking::getTown() const
{
    return town;
}

bool HotelBooking::isSmoke() const
{
    return smoke;
}
