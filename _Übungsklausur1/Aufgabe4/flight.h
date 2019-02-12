#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
using namespace std;

class Flight
{
public:
    Flight(string fromDest, string toDest);
    void book();
    void cancel();
    void show_bookings();
    int countBookedSeats();
    string getFromDestination() const;
    string getToDestination() const;

private:
    string seats[22][6];
    string fromDestination;
    string toDestination;
};

#endif // FLIGHT_H
