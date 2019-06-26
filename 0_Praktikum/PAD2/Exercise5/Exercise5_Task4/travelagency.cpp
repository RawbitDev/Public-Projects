// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "travelagency.h"

TravelAgency::TravelAgency(QWidget *parent) : mainWindow(parent)
{
    // Constructor
}

TravelAgency::~TravelAgency()
{
    // Destructor
}

void TravelAgency::readFile()
{
    file_dialog = QFileDialog::getOpenFileName(mainWindow,"Bitte zu importierende Datei auswählen:", file_dialog); // File Dialog to get the path of the file from the user
    if (file_dialog == "") return; // If the user cancels the file dialog
    string file_path = file_dialog.toStdString(); // Converting the Qstring to a string

    ifstream file(file_path); // Open up the file
    if (file) {
        int b_count=0, t_count=0, c_count=0, line_count=0;
        double price_sum=0;
        stringstream linestream;
        vector <string> rows;
        string line="", row="";

        // Temp copys of the original vectors, so we can discard the changes if an error was encountered
        List allBookingsTemp = allBookings;
        vector <Travel*> allTravelsTemp = allTravels;
        vector <Customer*> allCustomersTemp = allCustomers;

        while (getline(file, line)) { // Get one line at the time
            linestream << line; // Copy that line into a stringstream
            while(getline(linestream, row, '|')){ // Split it in its rows
                rows.push_back(row); // Add every row to the vector
            }

            // Creating a new object with the data of the current line by using the constructor of the subclass and pushing it into the booking vector
            line_count++;
            try{
                if (rows.at(0) == "F") {
                    allBookingsTemp.push_back(new FlightBooking(stol(rows.at(1)), stod(rows.at(2)), rows.at(3), rows.at(4), stol(rows.at(5)), rows.at(8), rows.at(9), rows.at(10), rows.at(11).at(0)));
                } else if (rows.at(0) == "H") {
                    allBookingsTemp.push_back(new HotelBooking(stol(rows.at(1)), stod(rows.at(2)), rows.at(3), rows.at(4), stol(rows.at(5)), rows.at(8), rows.at(9), (rows.at(10) == "1")));
                } else if (rows.at(0) == "R") {
                    allBookingsTemp.push_back(new RentalCarReservation(stol(rows.at(1)), stod(rows.at(2)), rows.at(3), rows.at(4), stol(rows.at(5)), rows.at(8), rows.at(9), rows.at(10), rows.at(11)));
                }
            } catch(...) {
                throw invalid_argument("> Datensatz konnte nicht eingelesen werden.\n> Fehlendes Attribut in Zeile " + to_string(line_count) + " erkannt!");
            }

            // Checking first row for correct data
            if (rows.at(0) == "F" || rows.at(0) == "H" || rows.at(0) == "R") {
                // Create the customer if they not already exist
                if (findCustomer(stol(rows.at(6)), allCustomersTemp) == nullptr) {
                    allCustomersTemp.push_back(new Customer(stol(rows.at(6)), rows.at(7)));
                    c_count++;
                }
                // Create the travel if it not already exists
                if (findTravel(stol(rows.at(5)), allTravelsTemp) == nullptr) {
                    allTravelsTemp.push_back(new Travel(stol(rows.at(5)), stol(rows.at(6))));
                    t_count++;
                }
                // Add the booking and travel to their lists
                findCustomer(stol(rows.at(6)), allCustomersTemp)->addTravel(findTravel(stol(rows.at(5)), allTravelsTemp));
                findTravel(stol(rows.at(5)), allTravelsTemp)->addBooking(findBooking(stol(rows.at(1)), allBookingsTemp));

                b_count++;
                price_sum += stod(rows.at(2));
            } else {
                throw invalid_argument("> Datensatz konnte nicht eingelesen werden.\n> In Zeile " + to_string(line_count) + " wird versucht ein ungültiges Objekt anzulegen!");
            }

            linestream.clear();
            rows.clear();
        }
        file.close();

        // Submitting the changes to the original vectors
        allBookings = allBookingsTemp;
        allTravels = allTravelsTemp;
        allCustomers = allCustomersTemp;

        string price_output = to_string(price_sum);
        price_output = price_output.substr(0, price_output.find(".") + 3); // Removing the unnecessary zeros at the end of the price
        QMessageBox::information(mainWindow, "Einleseergebnis", ("Es wurden " + QString::number(b_count) + " Buchungen, " + QString::number(c_count) + " Kunden und " + QString::number(t_count) + " Reisen\nim Gesamtwert von " + QString::fromStdString(price_output) + " € eingelesen."));

    } else {
        throw runtime_error("> Datei konnte nicht geöffnet werden!");
    }
}

// Search for a booking in the booking vector
Booking *TravelAgency::findBooking(long id)
{
    for(int i=0; i<int(allBookings.size()); i++) {
        if (allBookings.at(size_t(i))->getId() == id) {
            return allBookings.at(size_t(i));
        }
    }
    return nullptr; // Return a null pointer if the booking wasn't found
}

// Search for a travel in the booking travel
Travel *TravelAgency::findTravel(long id)
{
    for(int i=0; i<int(allTravels.size()); i++) {
        if (allTravels.at(size_t(i))->getId() == id) {
            return allTravels.at(size_t(i));
        }
    }
    return nullptr; // Return a null pointer if the travel wasn't found
}

// Search for a customer in the customer travel
Customer *TravelAgency::findCustomer(long id)
{
    for(int i=0; i<int(allCustomers.size()); i++) {
        if (allCustomers.at(size_t(i))->getId() == id) {
            return allCustomers.at(size_t(i));
        }
    }
    return nullptr; // Return a null pointer if the customer wasn't found
}

List TravelAgency::getAllBookings() const
{
    return allBookings;
}

vector<Customer *> TravelAgency::getAllCustomers() const
{
    return allCustomers;
}

int TravelAgency::getNumBookings()
{
    return static_cast<int>(allBookings.size());
}

int TravelAgency::getPercentSmokerHotels()
{
    int count_hotel=0, count_smoke_hotel=0;
    for (unsigned int i=0; i<allBookings.size(); i++) {
        if (HotelBooking* hotel = dynamic_cast<HotelBooking*> (allBookings.at(i))) { // Check if the Booking is a hotel
            count_hotel++;
            if (hotel->isSmoke()) // Check if it's also a smoker hotel
                count_smoke_hotel++;
        }
    }
    return (100/count_hotel)*count_smoke_hotel; // Calculate the percentage
}

vector<Travel *> TravelAgency::getAllTravels() const
{
    return allTravels;
}

// Search for a booking in the booking vector
Booking *TravelAgency::findBooking(long id, List Bookings)
{
    for(int i=0; i<int(Bookings.size()); i++) {
        if (Bookings.at(size_t(i))->getId() == id) {
            return Bookings.at(size_t(i));
        }
    }
    return nullptr; // Return a null pointer if the booking wasn't found
}

// Search for a travel in the booking travel
Travel *TravelAgency::findTravel(long id, vector <Travel*> Travels)
{
    for(int i=0; i<int(Travels.size()); i++) {
        if (Travels.at(size_t(i))->getId() == id) {
            return Travels.at(size_t(i));
        }
    }
    return nullptr; // Return a null pointer if the travel wasn't found
}

// Search for a customer in the customer travel
Customer *TravelAgency::findCustomer(long id, vector <Customer*> Customers)
{
    for(int i=0; i<int(Customers.size()); i++) {
        if (Customers.at(size_t(i))->getId() == id) {
            return Customers.at(size_t(i));
        }
    }
    return nullptr; // Return a null pointer if the customer wasn't found
}
