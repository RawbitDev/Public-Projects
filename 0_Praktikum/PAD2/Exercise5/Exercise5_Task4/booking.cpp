// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "booking.h"

Booking::Booking(long id, double price, string fromDate, string toDate, long travelId) : id(id), travelId(travelId), price(price), fromDate(fromDate), toDate(toDate)
{
    // Constructor
}

Booking::~Booking()
{
    // Destructor
}

long Booking::getId() const
{
    return id;
}

double Booking::getPrice() const
{
    return price;
}

string Booking::getFromDate() const
{
    return fromDate;
}

string Booking::getToDate() const
{
    return toDate;
}

string Booking::showDetails()
{
    return "";
}

long Booking::getTravelId() const
{
    return travelId;
}
