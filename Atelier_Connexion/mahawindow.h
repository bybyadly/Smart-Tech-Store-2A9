#ifndef MAHAWINDOW_H
#define MAHAWINDOW_H

#include <QMainWindow>
#include "employee.h"
#include "historique.h"
#include "arduinomaha.h"

namespace Ui {
class mahawindow;
}

class mahawindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mahawindow(QWidget *parent = nullptr);
    ~mahawindow();

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



    void on_open_clicked();

    void on_close_clicked();
    void update_label();

private:
    Ui::mahawindow *ui;
    employee E;
    Historique HI;
    arduinomaha M1;
    QByteArray data;
};

#endif // MAHAWINDOW_H
