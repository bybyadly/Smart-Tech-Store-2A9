#include "loginskander.h"
#include "ui_loginskander.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtCharts>
#include <QPieSlice>
#include <QSqlQuery>
#include <QPieSeries>
#include <QRegExpValidator>
#include "mainwindow.h"
#include "skanderwindow.h"
#include "loginn.h"

skanderwindow *sl;
loginskander::loginskander(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginskander)
{
    ui->setupUi(this);
}

loginskander::~loginskander()
{
    delete ui;
}



void loginskander::on_pb_login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    if(username ==  "skander" && password == "skander") {
        QMessageBox::information(this, "Login", "Username and password is correct");
        //hide();
        sl = new skanderwindow(this);
        sl->show();
    }
    else  if(username ==  "admin" && password == "admin" ) {
        QMessageBox::information(this, "Login", "Bienvenue ADMINISTRATEUR : Voici votre accés");
        //hide();
        sl = new skanderwindow(this);
        sl->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Username or password is not correct, Veuillez réessayer");
    }
}
