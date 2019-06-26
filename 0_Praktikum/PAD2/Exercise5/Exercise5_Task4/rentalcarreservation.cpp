// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "rentalcarreservation.h"

RentalCarReservation::RentalCarReservation(long id, double price, string fromDate, string toDate, long travelId, string pickupLocation, string returnLocation, string company, string insuranceType) : Booking(id, price, fromDate, toDate, travelId), pickupLocation(pickupLocation), returnLocation(returnLocation), company(company), insuranceType(insuranceType)
{
    // Constructor
}

RentalCarReservation::~RentalCarReservation()
{
    // Destructor
}

string RentalCarReservation::showDetails()
{
    return insuranceType;
}

string RentalCarReservation::getCompany() const
{
    return company;
}

string RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

string RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}
