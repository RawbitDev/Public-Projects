// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef LISTDIALOG_H
#define LISTDIALOG_H

#include <QDialog>
#include <vector>
#include <customer.h>
using namespace std;

namespace Ui {
class ListDialog;
}

class ListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ListDialog(QWidget *parent = nullptr);
    ~ListDialog();
    void searchCustomer(vector<Customer*>, string);

private:
    Ui::ListDialog *ui;
};

#endif // LISTDIALOG_H
