#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <iostream>
#include <vector>
#include <rentalcarreservation.h>
#include <flightbooking.h>
#include <hotelbooking.h>
#include <fstream>
#include <sstream>
using namespace std;

class TravelAgency
{
private:
    vector <RentalCarReservation*> rentalCarReservations;
    vector <HotelBooking*> hotelBookings;
    vector <FlightBooking*> flightBookings;

public:
    TravelAgency();
    void readFile();
};

#endif // TRAVELAGENCY_H
