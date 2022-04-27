#include "loginelaa.h"
#include "ui_loginelaa.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtCharts>
#include <QPieSlice>
#include <QSqlQuery>
#include <QPieSeries>
#include <QRegExpValidator>
#include "mainwindow.h"
#include "elaawindow.h"

elaawindow *e;


loginelaa::loginelaa(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginelaa)
{
    ui->setupUi(this);
}

loginelaa::~loginelaa()
{
    delete ui;
}

void loginelaa::on_pb_login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    if(username ==  "elaa" && password == "elaa") {
        QMessageBox::information(this, "Login", "Username and password is correct");
        //hide();
        e = new elaawindow(this);
        e->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Username and password is not correct");
    }
}
