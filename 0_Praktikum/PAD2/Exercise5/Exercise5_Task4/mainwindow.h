// Exercise 5 von Andreas Müller (761579) und Ramon Walther (761312) -> Gruppe: Mo12x-1
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <travelagency.h>
#include <listdialog.h>
#include <auditresultdialog.h>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resetTable();
    void resetDetails();
    void refreshDetails(int index);

private slots:
    void on_actionDatei_einlesen_triggered();
    void on_actionBuchungen_anzeigen_triggered();
    void on_actionProgramm_beenden_triggered();
    void on_tableWidget_itemSelectionChanged();
    void on_pushButton_clicked();
    void on_actionBuchungsliste_leeren_triggered();
    void on_actionKundensuche_triggered();
    void on_actionBuchungen_pr_fen_triggered();

private:
    Ui::MainWindow *ui;
    TravelAgency *ta;
};

#endif // MAINWINDOW_H
