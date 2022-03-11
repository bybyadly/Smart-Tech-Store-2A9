#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"
#include <QMainWindow>

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



private:
    Ui::MainWindow *ui;
    Produit Pro;
};

#endif // MAINWINDOW_H
