// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <list.h>
#include <booking.h>
#include <travel.h>
#include <customer.h>
#include <flightbooking.h>
#include <hotelbooking.h>
#include <rentalcarreservation.h>
using namespace std;

class TravelAgency
{
public:
    TravelAgency(QWidget *parent = nullptr);
    ~TravelAgency();
    void readFile();
    Booking* findBooking(long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id); 
    Booking* findBooking(long id, List Bookings);
    Travel* findTravel(long id, vector <Travel*> Travels);
    Customer* findCustomer(long id, vector <Customer*> Customers);
    List getAllBookings() const;
    vector<Travel *> getAllTravels() const;
    vector<Customer*> getAllCustomers() const;
    int getNumBookings();
    int getPercentSmokerHotels();

private:
    QWidget *mainWindow;
    QString file_dialog;
    List allBookings;
    vector <Travel*> allTravels;
    vector <Customer*> allCustomers;
};

#endif // TRAVELAGENCY_H
