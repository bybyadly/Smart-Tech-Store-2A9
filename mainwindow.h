#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include <QMainWindow>
#include "historique.h"
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
    void on_ajouter_clicked();

    void on_supprimer_clicked();

    void on_button_modifier_clicked();

   // void on_pushButton_3_clicked();

  //  void on_tri_clicked();

    void on_historique_clicked();

    //void on_chercher_clicked();

 //   void on_pushButton_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_2_clicked();


    void on_l_r_textChanged(const QString &arg1);

    void on_pushButton_clicked();



    void on_pushButton_2_clicked();



    void on_stat_clicked();

    void on_pushButton_historrr_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Employe E;
    Historique HI;
};

#endif // MAINWINDOW_H
