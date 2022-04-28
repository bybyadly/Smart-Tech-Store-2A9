#include "menu.h"
#include "ui_menu.h"
#include "produit.h"
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
#include "loginaziz.h"
#include "ui_loginaziz.h"
#include "loginelaa.h"
#include "mahawindow.h"
#include "skanderwindow.h"
#include "ui_menu.h"
#include "clients.h"
#include "mainwindow.h"
#include "loginskander.h"
#include <QTimer>
#include <QDateTime>
#include "loginmaha.h"

loginaziz *c;
loginn *l,*l1;
loginelaa *el;
loginmaha *mh;
loginskander *sk;


Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Hp/Desktop/techland.png") ;
    //QPixmap pix1("C:/Users/Hp/Desktop/employés.png");
    ui->image->setPixmap(pix);
    //ui->icon_emp->setPixmap(pix1);

    QFile styleSheetFile("C:/Users/Hp/Desktop/gittt/Smart-Tech-Store-2A9/Atelier_Connexion/Perstfic.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    Menu::setStyleSheet(styleSheet);


    QTimer *timer=new QTimer(this);
    connect(timer , SIGNAL(timeout()),this,SLOT(showtime()));
    timer->start();


}

Menu::~Menu()
{
    delete ui;
}



void Menu::on_gestion_produits_clicked()
{
    l=new loginn(this);
l->show();





   }




void Menu::on_quitter_clicked()
{
    exit(EXIT_FAILURE);
}

void Menu::on_gestion_clients_clicked()
{

   c=new loginaziz(this);
   c->show();
}

void Menu::on_gestion_fournisseurs_clicked()
{
    el=new loginelaa(this);
    el->show();
}

void Menu::on_gestion_employee_clicked()
{


        mh=new loginmaha(this);
        mh->show();

}

void Menu::on_gestion_factures_clicked()
{
    sk=new loginskander(this);
    sk->show();
}

void Menu::on_cleardata_clicked()
{
    Produit p1;
    Clients c1;
    fournisseur f1;
    facture fac1;
    employee e1;

        bool test=p1.supprimerprods();
        bool test1=c1.supprimerclients();
        bool test2=f1.supprimerfour();
        bool test3=fac1.supprimerfacs();
        bool test4=e1.supprimeremps();
        QMessageBox msgbox;

        if (test && test1 && test2 && test3 && test4){


                QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                      QObject::tr("Suppression effectuée"),
                                      QMessageBox::Ok
                                      );
            }else{
                QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                                      QObject::tr("Suppression non effectuée"),
                                      QMessageBox::Cancel
                                      );
            }
}

///////////////////////////////////////////////////////////////////
void Menu::showtime()
{
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->time->setText(time_text);

}
