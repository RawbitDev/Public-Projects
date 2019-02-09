#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
using namespace std;

class Flight
{
public:
    Flight();
    void book();
    void cancel();
    void show_bookings();
    void setFromDestination(const string &value);
    void setToDestination(const string &value);
    int countBookedSeats();

private:
    string seats[22][6];
    string fromDestination;
    string toDestination;
};

#endif // FLIGHT_H
