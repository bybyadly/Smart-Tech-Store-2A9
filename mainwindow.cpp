#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "clients.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableViewAffichuer->setModel(CL.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Ajouter_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    int Cin = ui->lineEdit_Cin->text().toUInt();
    int Num_tel = ui->lineEdit_TEL->text().toUInt();
    QString Nom = ui->lineEdit_Nom->text();
    QString Prenom = ui->lineEdit_Prenom->text();
    QString Email = ui->lineEdit_Email->text();
    QString Type;
    QString Sexe;
    if (ui->Homme->isChecked()){
        Sexe = "Homme";
    }
    if (ui->Femme->isChecked()){
        Sexe = "Femme";
    }
    if (ui->Passage->isChecked()){
        Type = "Passage";
    }
    if (ui->Fidele->isChecked()){
        Type = "Fidele";
    }
    Clients C (id, Cin, Num_tel, Nom, Prenom, Email, Sexe, Type);

    bool test = C.ajouter();

    if (test){
        ui->tableViewAffichuer->setModel(CL.afficher());
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                              QObject::tr("Ajout effectué"),
                              QMessageBox::Ok
                              );
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Ajouter non effectué"),
                              QMessageBox::Cancel
                              );
    }

}

void MainWindow::on_pushButton_Suppression_clicked()
{
    int id = ui->lineEdit_ID_Supression->text().toInt();
    bool test = CL.supprimer(id);

    if (test){
        ui->tableViewAffichuer->setModel(CL.afficher());
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                              QObject::tr("Suppression effectué"),
                              QMessageBox::Ok
                              );
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Suppression non effectué"),
                              QMessageBox::Cancel
                              );
    }
}

void MainWindow::on_pushButton_Modifer_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    int Cin = ui->lineEdit_Cin->text().toUInt();
    int Num_tel = ui->lineEdit_TEL->text().toUInt();
    QString Nom = ui->lineEdit_Nom->text();
    QString Prenom = ui->lineEdit_Prenom->text();
    QString Email = ui->lineEdit_Email->text();
    QString Type;
    QString Sexe;
    if (ui->Homme->isChecked()){
        Sexe = "Homme";
    }
    if (ui->Femme->isChecked()){
        Sexe = "Femme";
    }
    if (ui->Passage->isChecked()){
        Type = "Passage";
    }
    if (ui->Fidele->isChecked()){
        Type = "Fidele";
    }
    Clients C (id, Cin, Num_tel, Nom, Prenom, Email, Sexe, Type);

    bool test = C.modifier();

    if (test){
        ui->tableViewAffichuer->setModel(CL.afficher());
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                              QObject::tr("Ajout effectué"),
                              QMessageBox::Ok
                              );
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Ajouter non effectué"),
                              QMessageBox::Cancel
                              );
    }

}
