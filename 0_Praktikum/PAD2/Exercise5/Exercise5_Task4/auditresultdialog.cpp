// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#include "auditresultdialog.h"
#include "ui_auditresultdialog.h"

AuditResultDialog::AuditResultDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuditResultDialog)
{
    ui->setupUi(this);
}

AuditResultDialog::~AuditResultDialog()
{
    delete ui;
}

void AuditResultDialog::auditBookings(vector<Travel *> TravelList)
{
    ui->tableWidget->setRowCount(int(TravelList.size())); // Set the rows of the table to the number of travels

    // Creating and setting the icons
    for (int i=0; i<int(TravelList.size()); i++) {
        // Setting the items for every row of the table
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(to_string(TravelList.at(size_t(i))->getId()))));
        if(TravelList.at(size_t(i))->checkMissingHotel() == false) {
            QTableWidgetItem *icon_item_hotelMissing = new QTableWidgetItem;
            QIcon icon_hotelMissing(":/audit/res/audit_result/hotel_missing.png");
            icon_item_hotelMissing->setIcon(icon_hotelMissing);
            ui->tableWidget->setItem(i, 1, icon_item_hotelMissing);
        } else {
            QTableWidgetItem *icon_item_fine = new QTableWidgetItem;
            QIcon icon_fine(":/audit/res/audit_result/fine.png");
            icon_item_fine->setIcon(icon_fine);
            ui->tableWidget->setItem(i, 1, icon_item_fine);
        }
        if(TravelList.at(size_t(i))->checkNeedlessHotel() == false) {
            QTableWidgetItem *icon_item_hotelNeedless = new QTableWidgetItem;
            QIcon icon_hotelNeedless(":/audit/res/audit_result/hotel_needless.png");
            icon_item_hotelNeedless->setIcon(icon_hotelNeedless);
            ui->tableWidget->setItem(i, 2, icon_item_hotelNeedless);
        } else {
            QTableWidgetItem *icon_item_fine = new QTableWidgetItem;
            QIcon icon_fine(":/audit/res/audit_result/fine.png");
            icon_item_fine->setIcon(icon_fine);
            ui->tableWidget->setItem(i, 2, icon_item_fine);
        }
        if(TravelList.at(size_t(i))->checkRoundtrip() == false) {
            QTableWidgetItem *icon_item_roundtrip = new QTableWidgetItem;
            QIcon icon_roundtrip(":/audit/res/audit_result/roundtrip.png");
            icon_item_roundtrip->setIcon(icon_roundtrip);
            ui->tableWidget->setItem(i, 3, icon_item_roundtrip);
        } else {
            QTableWidgetItem *icon_item_fine = new QTableWidgetItem;
            QIcon icon_fine(":/audit/res/audit_result/fine.png");
            icon_item_fine->setIcon(icon_fine);
            ui->tableWidget->setItem(i, 3, icon_item_fine);
        }
    }
}
