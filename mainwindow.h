#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "clients.h"
#include <QMainWindow>
#include "historiqueclients.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    Clients CL;
    HistoriqueClients Hist;
};
#endif // MAINWINDOW_H
