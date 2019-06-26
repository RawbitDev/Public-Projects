// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include <iostream>
#include <booking.h>
using namespace std;

class RentalCarReservation : public Booking
{
public:
    RentalCarReservation(long id, double price, string fromDate, string toDate, long travelId, string pickupLocation, string returnLocation, string company, string insuranceType);
    ~RentalCarReservation();
    virtual string showDetails();
    string getCompany() const;
    string getPickupLocation() const;
    string getReturnLocation() const;

private:
    string pickupLocation, returnLocation, company, insuranceType;
};

#endif // RENTALCARRESERVATION_H
