// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "flightbooking.h"

FlightBooking::FlightBooking(long id, double price, string fromDate, string toDate, long travelId, string fromDest, string toDest, string airline, char seatPref) : Booking(id, price, fromDate, toDate, travelId), fromDest(fromDest), toDest(toDest), airline(airline), seatPref(seatPref)
{
    // Constructor
}

FlightBooking::~FlightBooking()
{
    // Destructor
}

string FlightBooking::showDetails()
{
    if (seatPref == 'A') {return "Gang";}
    else if (seatPref == 'W') {return "Fenster";}
    return "Error";
}

string FlightBooking::getAirline() const
{
    return airline;
}

string FlightBooking::getFromDest() const
{
    return fromDest;
}

string FlightBooking::getToDest() const
{
    return toDest;
};
