#ifndef FLIGHTPLAN_H
#define FLIGHTPLAN_H

#include <iostream>
#include <flight.h>
#include <vector>
using namespace std;

class Flightplan
{
public:
    Flightplan();
    void book();
    void cancel();
    void show_bookings();
    void initialize();
    void overview();
private:
    vector <Flight> Flights;
};

#endif // FLIGHTPLAN_H
