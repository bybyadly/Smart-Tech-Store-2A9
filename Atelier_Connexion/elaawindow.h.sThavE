#ifndef ELAAWINDOW_H
#define ELAAWINDOW_H

#include "fournisseur.h"
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "arduino.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class elaawindow;
}

class elaawindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit elaawindow(QWidget *parent = nullptr);
    ~elaawindow();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_Supprimer_clicked();
    void on_pushButton_2_clicked();



    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_chercher_clicked();

    void on_pushButton_5_clicked();

    void on_pb_image_clicked();



    void on_pushButton_6_clicked();

    void on_pushButton_exportpdf_clicked();

    void on_pushButton_checkpDf_clicked();



private:
    Ui::elaawindow *ui;
    fournisseur f, ftu;
};

#endif // ELAAWINDOW_H
