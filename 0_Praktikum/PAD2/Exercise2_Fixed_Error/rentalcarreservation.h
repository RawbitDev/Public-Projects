#ifndef RENTALCARRESERVATIONS_H
#define RENTALCARRESERVATIONS_H
#include <booking.h>
using namespace std;

class RentalCarReservation : public Booking
{
private:
    string pickupLocation;
    string returnLocation;
    string company;

public:
    RentalCarReservation();
    string getPickupLocation() const;
    void setPickupLocation(const string &value);
    string getReturnLocation() const;
    void setReturnLocation(const string &value);
    string getCompany() const;
    void setCompany(const string &value);
};

#endif // RENTALCARRESERVATIONS_H
