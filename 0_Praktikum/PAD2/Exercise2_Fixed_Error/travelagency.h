#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <travel.h>
#include <customer.h>
#include <booking.h>
#include <flightbooking.h>
#include <hotelbooking.h>
#include <rentalcarreservation.h>

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class TravelAgency
{
private:
    vector <Booking*> allBookings;
    vector <Customer*> allCustomers;
    vector <Travel*> allTravels;

public:
    TravelAgency();
    void readFile();
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);
    void createRentalCarReservation(stringstream strings);
    void createHotelBooking(stringstream strings);
    void createFlightBooking(stringstream strings);
};

#endif // TRAVELAGENCY_H
