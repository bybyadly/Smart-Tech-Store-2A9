#include "loginaziz.h"
#include "ui_loginaziz.h"
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

azizwindow *cl;
loginaziz::loginaziz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginaziz)
{
    ui->setupUi(this);
}

loginaziz::~loginaziz()
{
    delete ui;
}

void loginaziz::on_pb_login_clicked()
{

    QString username = ui->username->text();
    QString password = ui->password->text();

    if(username ==  "aziz" && password == "aziz" ) {
        QMessageBox::information(this, "Login", "Bienvenue Aziz : Voici votre accés");
        //hide();
        cl = new azizwindow(this);
        cl->show();
    }
    else  if(username ==  "admin" && password == "admin" ) {
        QMessageBox::information(this, "Login", "Bienvenue ADMINISTRATEUR : Voici votre accés");
        //hide();
        cl = new azizwindow(this);
        cl->show();
    }


    else {
        QMessageBox::warning(this,"Login", "Username or password is not correct , veuillez réssayer");
    }
}
