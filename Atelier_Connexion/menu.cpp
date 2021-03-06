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

MainWindow *p;
Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    QFile styleSheetFile("C:/Users/Hp/Desktop/gittt/Smart-Tech-Store-2A9/Atelier_Connexion/Perstfic.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    Menu::setStyleSheet(styleSheet);
}

Menu::~Menu()
{
    delete ui;
}



void Menu::on_gestion_produits_clicked()
{
    hide();
   p=new MainWindow(this);
   p->show();
}

void Menu::on_quitter_clicked()
{
    exit(EXIT_FAILURE);
}
