#ifndef AZIZWINDOW_H
#define AZIZWINDOW_H

#include "historiqueclients.h"
#include "clients.h"
#include <QMainWindow>
#include "arduinoaziz.h"

namespace Ui {
class azizwindow;
}

class azizwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit azizwindow(QWidget *parent = nullptr);
    ~azizwindow();

private slots:
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Suppression_clicked();

    void on_pushButton_Modifer_clicked();

    void on_pushButton_trier_clicked();

    void on_pushButton_Rechercher_clicked();



    void on_pushButton_actualiser_clicked();

    void on_pushButtonActualiserHistorique_clicked();

    void on_pushButtonGenerePDF_clicked();

    void on_pushButton_AfficherPDF_clicked();

    void on_pushButton_stat_clicked();

    void on_pushButton_imprimer_clicked();

    void on_pushButton_sombre_clicked();

    void on_pushButton_blanc_clicked();

    void on_pushButton_trier_nom_clicked();

    void on_ouvrir_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::azizwindow *ui;
    Clients CL;
    historiqueClients Hist;
    QString data;
     Arduinoaziz A;
};

#endif // AZIZWINDOW_H
