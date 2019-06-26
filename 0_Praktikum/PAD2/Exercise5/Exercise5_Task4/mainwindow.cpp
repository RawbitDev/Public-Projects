// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ta = new TravelAgency(this);
    resetTable(); // Setting the headers
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDatei_einlesen_triggered()
{
    try {
        ta->readFile();
    } catch (exception &e) {
        QMessageBox::critical(this, "Error", ("Fehler beim Einlesen:\n" + QString::fromStdString(e.what())));
    }

    if (ta->getAllBookings().size() > 0)
        ui->actionBuchungen_anzeigen->setEnabled(true); // Enable the Button to show the bookings

    if (ta->getAllCustomers().size() > 0)
        ui->actionKundensuche->setEnabled(true); // Enable the Button to search for a customer

    if (ta->getAllTravels().size() > 0)
        ui->actionBuchungen_pr_fen->setEnabled(true); // Enable the Button to check the bookings
}

void MainWindow::on_actionBuchungen_anzeigen_triggered()
{
    resetTable(); // Clearing the containers and setting the headers
    ui->tableWidget->setRowCount(int(ta->getAllBookings().size())); // Set the rows of the table to the number of bookings

    if (ta->getAllBookings().size() > 0) {
        ui->actionBuchungen_anzeigen->setEnabled(false); // Disable the Button to show the bookings
        ui->actionBuchungsliste_leeren->setEnabled(true); // Enable the Button to clear the booking list
    }

    for (int i=0; i<int(ta->getAllBookings().size()); i++) {
        string id = to_string(ta->getAllBookings().at(size_t(i))->getId()); // Get the id of the current booking
        string price = to_string(ta->getAllBookings().at(size_t(i))->getPrice()); // Get the price of the current booking
        string customer = ta->findCustomer(ta->findTravel(ta->getAllBookings().at(size_t(i))->getTravelId())->getCustomerId())->getName(); // Get the name of the current customer
        price = price.substr(0, price.find(".") + 3); // Removing the unnecessary zeros at the end of the price

        // Setting the items for every columns of the table
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(id)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(price + " €")));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(customer)));
    }
}

void MainWindow::on_actionProgramm_beenden_triggered()
{
    close();
}

void MainWindow::resetTable()
{
    ui->tableWidget->clear(); // Clearing the table
    ui->tableWidget->setColumnCount(3); // Setting the number of columns to 3
    ui->tableWidget->setRowCount(0); // Setting the number of rows to 0 (for now)
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Buchungsnummer")); //Setting the header for every column of the table
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Preis"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Kunde"));
    resetDetails();
}

void MainWindow::resetDetails()
{
    // Reset everything to default values
    ui->lineEdit_bookingnumber->clear();
    ui->calendarWidget_from->showToday();
    ui->calendarWidget_to->showToday();
    ui->doubleSpinBox_price->clear();
    ui->spinBox_travel->clear();
    ui->lineEdit_customer->clear();
    ui->lineEdit_details_1->clear();
    ui->lineEdit_details_2->clear();
    ui->lineEdit_details_3->clear();
    ui->lineEdit_details_4->clear();

    this->setFixedWidth(805); // Shrink the main window
    ui->groupBox_main->setEnabled(false); // Disable all edit fields etc.
    ui->groupBox_details->setVisible(false); // Hide the details for now
}

// Functions to easier get the QString from other data types
QString toQStr(string s) {
    return QString::fromStdString(s);
}
QString toQStr(long l) {
    return QString::fromStdString(to_string(l));
}

void MainWindow::refreshDetails(int index)
{
    if (index >= 0 && index <= int(ta->getAllBookings().size())) {

        if (ui->groupBox_main->isEnabled() == false)
            ui->groupBox_main->setEnabled(true); // Enable all edit fields etc.

        if (ui->groupBox_details->isVisible() == false) {
            this->setFixedWidth(1205); // Resize the main window
            ui->groupBox_details->setVisible(true); // Show the details
        }

        Booking* selectedBooking = ta->getAllBookings().at(size_t(index)); // Get the selected booking
        ui->lineEdit_bookingnumber->setText(toQStr(selectedBooking->getId())); // Setting the id of the selected booking to the output field
        ui->calendarWidget_from->setSelectedDate(QDate(stoi(selectedBooking->getFromDate().substr(0, 4)),stoi(selectedBooking->getFromDate().substr(4, 2)),stoi(selectedBooking->getFromDate().substr(6, 2)))); // Selecting the from_date on the first calendar
        ui->calendarWidget_to->setSelectedDate(QDate(stoi(selectedBooking->getToDate().substr(0, 4)),stoi(selectedBooking->getToDate().substr(4, 2)),stoi(selectedBooking->getToDate().substr(6, 2)))); // Selecting the to_date on the second calendar
        ui->doubleSpinBox_price->setValue(selectedBooking->getPrice());
        ui->spinBox_travel->setValue(selectedBooking->getTravelId());
        ui->lineEdit_customer->setText(toQStr(ta->findCustomer(ta->findTravel(selectedBooking->getTravelId())->getCustomerId())->getName()));

        if (FlightBooking* flight = dynamic_cast<FlightBooking*> (selectedBooking)) {
            ui->lineEdit_details_3->setVisible(true);
            ui->label_details_4->setVisible(true);
            ui->lineEdit_details_4->setVisible(true);
            ui->groupBox_details->setTitle("Flugdetails");
            ui->label_details_1->setText("Airline");
            ui->lineEdit_details_1->setText(toQStr(flight->getAirline()));
            ui->label_details_2->setText("Abflugdestination");
            ui->lineEdit_details_2->setText(toQStr(flight->getFromDest()));
            ui->label_details_3->setText("Zieldestination");
            ui->lineEdit_details_3->setText(toQStr(flight->getToDest()));
            ui->label_details_4->setText("Sitzplatzpräferenz");
            ui->lineEdit_details_4->setText(toQStr(selectedBooking->showDetails()));

        } else if (HotelBooking* hotel = dynamic_cast<HotelBooking*> (selectedBooking)) {
            ui->lineEdit_details_3->setVisible(false);
            ui->label_details_4->setVisible(false);
            ui->lineEdit_details_4->setVisible(false);
            ui->groupBox_details->setTitle("Hoteldetails");
            ui->label_details_1->setText("Hotel");
            ui->lineEdit_details_1->setText(toQStr(hotel->getHotel()));
            ui->label_details_2->setText("Stadt");
            ui->lineEdit_details_2->setText(toQStr(hotel->getTown()));
            ui->label_details_3->setText(toQStr(selectedBooking->showDetails()));

        } else if (RentalCarReservation* rentalCar = dynamic_cast<RentalCarReservation*> (selectedBooking)) {
            ui->lineEdit_details_3->setVisible(true);
            ui->label_details_4->setVisible(true);
            ui->lineEdit_details_4->setVisible(true);
            ui->groupBox_details->setTitle("Mietwagendetails");
            ui->label_details_1->setText("Autovermietung");
            ui->lineEdit_details_1->setText(toQStr(rentalCar->getCompany()));
            ui->label_details_2->setText("Abholstation");
            ui->lineEdit_details_2->setText(toQStr(rentalCar->getPickupLocation()));
            ui->label_details_3->setText("Rückgabestation");
            ui->lineEdit_details_3->setText(toQStr(rentalCar->getReturnLocation()));
            ui->label_details_4->setText("Versicherung");
            ui->lineEdit_details_4->setText(toQStr(selectedBooking->showDetails()));
        }
    }
}

void MainWindow::on_tableWidget_itemSelectionChanged()
{
    refreshDetails(ui->tableWidget->currentRow());
}

void MainWindow::on_pushButton_clicked()
{
    resetDetails();
}

void MainWindow::on_actionBuchungsliste_leeren_triggered()
{
    resetTable();
    resetDetails();

    if (ta->getAllBookings().size() > 0) {
        ui->actionBuchungsliste_leeren->setEnabled(false); // Disable the Button to clear the booking list
        ui->actionBuchungen_anzeigen->setEnabled(true); // Enable the Button to show the bookings
    }
}

void MainWindow::on_actionKundensuche_triggered()
{
    QInputDialog input;
    string search = input.getText(this, "Kundensuche", "Name des Kunden:").toStdString(); // Get the search string
    if (search.size() > 0) { // Check if it's not an empty string
        ListDialog ld; // Create a new ListDialog
        ld.searchCustomer(ta->getAllCustomers(), search); // Sort the customer list
        ld.exec(); // Show the ListDialog
    }
}

void MainWindow::on_actionBuchungen_pr_fen_triggered()
{
    AuditResultDialog ard; // Create a new AuditResultDialog
    ard.auditBookings(ta->getAllTravels()); // Calculate the result
    ard.exec(); // Show the AuditResultDialog
}
