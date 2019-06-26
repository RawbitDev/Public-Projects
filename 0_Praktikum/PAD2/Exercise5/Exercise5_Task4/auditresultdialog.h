// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef AUDITRESULTDIALOG_H
#define AUDITRESULTDIALOG_H

#include <QDialog>
#include <travel.h>
using namespace std;

namespace Ui {
class AuditResultDialog;
}

class AuditResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AuditResultDialog(QWidget *parent = nullptr);
    ~AuditResultDialog();
    void auditBookings(vector<Travel*> TravelList);

private:
    Ui::AuditResultDialog *ui;
};

#endif // AUDITRESULTDIALOG_H
