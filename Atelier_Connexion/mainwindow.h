#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"
#include <QMainWindow>
#include "arduino.h"
#include "menu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();


    void on_pb_supprimer_clicked();

    void on_pb_afficher_clicked();

    void on_pb_exit_clicked();

    void on_pb_modifier_clicked();

    void on_pb_tridecroi_clicked();

    void on_pb_tricroi_clicked();



    void on_pb_rechercher_clicked();

    void on_pb_pdf_clicked();

    void on_pb_stats_clicked();

    void on_pb_verif_clicked();



    void on_Dark_clicked();

    void on_Light_clicked();

    void on_open_clicked();

    void on_closed_clicked();
     void update_label();



     void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Produit Pro;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
    Menu  *m;
};

#endif // MAINWINDOW_H
