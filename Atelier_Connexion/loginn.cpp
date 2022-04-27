#include "loginn.h"
#include "ui_loginn.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtCharts>
#include <QPieSlice>
#include <QSqlQuery>
#include <QPieSeries>
#include <QRegExpValidator>
#include "mainwindow.h"
#include "azizwindow.h"
#include "loginn.h"
#include "ui_loginn.h"


MainWindow *p;
loginn::loginn(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginn)
{
    ui->setupUi(this);
}

loginn::~loginn()
{
    delete ui;
}

void loginn::on_pb_login_clicked()
{


    QString username = ui->username->text();
    QString password = ui->password->text();

    if(username ==  "adly" && password == "adly") {
        QMessageBox::information(this, "Login", "Username and password is correct");
        //hide();
        p = new MainWindow(this);
        p->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Username and password is not correct");
    }


}
