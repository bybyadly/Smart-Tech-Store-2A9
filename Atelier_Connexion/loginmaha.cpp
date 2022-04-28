#include "loginmaha.h"
#include "ui_loginmaha.h"
#include "mahawindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtCharts>
#include <QPieSlice>
#include <QSqlQuery>
#include <QPieSeries>
#include <QRegExpValidator>

mahawindow *m;
loginmaha::loginmaha(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::loginmaha)
{
    ui->setupUi(this);
}

loginmaha::~loginmaha()
{
    delete ui;
}

void loginmaha::on_pb_login_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();

    if(username ==  "maha" && password == "maha") {
        QMessageBox::information(this, "Login", "Bienvenue Maha : Voici votre accés");
        //hide();
        m = new mahawindow(this);
        m->show();
    }
    else  if(username ==  "admin" && password == "admin" ) {
        QMessageBox::information(this, "Login", "Bienvenue ADMINISTRATEUR : Voici votre accés");
        //hide();
        m = new mahawindow(this);
        m->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Username or password is not correct, Veuillez réessayer");
    }
}
