#ifndef BOOKING_H
#define BOOKING_H
#include <iostream>
using namespace std;

class Booking
{
private:
    //TravelAgency *tA;
    //Travel *tr;
    long id;
    double price;
    long travelId;
    string fromDate;
    string toDate;

public:
    Booking();

    long getId() const;
    void setId(long value);
    double getPrice() const;
    void setPrice(double value);
    long getTravelId() const;
    void setTravelId(long value);
    string getFromDate() const;
    void setFromDate(const string &value);
    string getToDate() const;
    void setToDate(const string &value);
};

#endif // BOOKING_H
