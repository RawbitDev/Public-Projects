// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "listdialog.h"
#include "ui_listdialog.h"
double dist(string a, string b); // Check out the levenshtein.cpp for more info about this algorithm

ListDialog::ListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListDialog)
{
    ui->setupUi(this);
}

ListDialog::~ListDialog()
{
    delete ui;
}

void ListDialog::searchCustomer(vector<Customer*> CustomerList, string search)
{
    // Using a bubble sort to sort the vector by the dist to the search string
    if (CustomerList.size() >= 2) {

        for (unsigned int j=1; j<CustomerList.size(); j++) {
            for (unsigned int i=0; i<CustomerList.size()-j; i++) {
                if (dist(CustomerList.at(i)->getName(), search) > (dist(CustomerList.at(i+1)->getName(), search))) // Calculation the dist using the levenshtein distance
                    iter_swap(CustomerList.begin()+int(i),CustomerList.begin()+int(i+1)); // Swap the position of the two in the vector
            }
        }

        // Output the sorted customer list
        for (unsigned int i=0; i<CustomerList.size(); i++) {
            ui->listWidget->addItem(QString::fromStdString(to_string(CustomerList.at(i)->getId()) + "\t" + CustomerList.at(i)->getName())); // Add the items to the list
        }
    }
}
