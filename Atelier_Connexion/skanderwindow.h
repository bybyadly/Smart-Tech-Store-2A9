#ifndef SKANDERWINDOW_H
#define SKANDERWINDOW_H

#include <QMainWindow>
#include "facture.h"
#include "produit.h"
#include "fournisseur.h"
#include "clients.h"

namespace Ui {
class skanderwindow;
}

class skanderwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit skanderwindow(QWidget *parent = nullptr);
    ~skanderwindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_Supprimer_clicked();
    void on_pushButton_2_clicked();

    void on_bp_rechercher_clicked();

    void on_bp_tricroi_clicked();

    void on_bp_tridecroi_clicked();

    void on_pdf_clicked();

    void on_pushButton_3_clicked();

     void on_pb_excel_clicked();
    // void on_calcul_clicked();

     void on_excel_clicked();


     void on_afficher_clicked();

     void on_pushButton_4_clicked();

     void on_verifier_clicked();

private:
    Ui::skanderwindow *ui;
    facture Et, Etu;
    Produit Pro;
    Clients cli;
    fournisseur four;

};

#endif // SKANDERWINDOW_H
