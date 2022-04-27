#include "clients.h"

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QMessageBox>

Clients::Clients()
{

}
Clients::Clients(int ID, int Cin, int Num_tel, QString  Nom, QString Prenom, QString Email, QString Sexe, QString Type){
    this->ID=ID;
    this->Cin=Cin;
    this->Num_tel=Num_tel;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Email=Email;
    this->Sexe=Sexe;
    this->Type=Type;
}
bool Clients::ajouter(){
    QSqlQuery query;
    //QString res = QString::number(id);
    query.prepare("insert into Clients values (:ID, :Nom, :Prenom, :Email, :Cin, :Sexe, :Num_tel, :Type)");
    query.bindValue(":ID",ID);
    query.bindValue(":Cin", Cin);
    query.bindValue(":Num_tel", Num_tel);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":Email", Email);
    query.bindValue(":Sexe", Sexe);
    query.bindValue(":Type", Type);
    return query.exec();
}
QSqlQueryModel * Clients::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Clients");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("Numéro de téléphone"));
    model->setHeaderData(7,Qt::Horizontal, QObject::tr("Type"));

    return model;
}
bool Clients::supprimer(int id){
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("delete from Clients where ID_CLIENT = :ID");
    query.bindValue(":ID", res);
    return query.exec();
}
bool Clients::modifier(){
    QSqlQuery query;
    //QString res = QString::number(id);
    query.prepare("insert into Clients values (:ID, :Nom, :Prenom, :Email, :Cin, :Sexe, :Num_tel, :Type)");
    query.prepare("update Clients set NOM_CLIENT = :Nom, PRENOM_CLIENT = :Prenom, EMAIL_CLIENT = :Email, CIN_CLIENT = :Cin, SEXE_CLIENT = :Sexe, NUM_TEL_CLIENT = :Num_tel , TYPE_CLIENT = :Type where ID_CLIENT = :ID");
    query.bindValue(":ID",ID);
    query.bindValue(":Cin",Cin);
    query.bindValue(":Num_tel", Num_tel);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":Email", Email);
    query.bindValue(":Sexe", Sexe);
    query.bindValue(":Type", Type);
    return query.exec();
}

QSqlQueryModel * Clients::trier(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Clients ORDER BY ID_CLIENT");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("Numéro de téléphone"));
    model->setHeaderData(7,Qt::Horizontal, QObject::tr("Type"));
    return model;
}

QSqlQueryModel* Clients::trierNom(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Clients order by NOM_CLIENT");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("Numéro de téléphone"));
    model->setHeaderData(7,Qt::Horizontal, QObject::tr("Type"));
    return model;
}

QSqlQueryModel * Clients::rechercher(QString field){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from Clients where (NOM_CLIENT) LIKE '%"+field+"%' ");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Cin"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("Numéro de téléphone"));
    model->setHeaderData(7,Qt::Horizontal, QObject::tr("Type"));
    return model;
}
void Clients::printPDF_comptes()
{
    QPdfWriter pdf("C:/Users/Aziz Abrougui/Documents/generated_pdf_client.pdf");
    QPainter painter(&pdf);
    QFont font=painter.font();
    QMessageBox msgBox;
    QString idS = QString::number(ID) ;
    QString CinS = QString::number(Cin) ;
    QString Num_telS = QString::number(Num_tel) ;
    font.setPointSize(font.pointSize() * 2);
           painter.setFont(font);
           painter.setPen(Qt::black);
           painter.drawText(300,800 , "ID: ");
           painter.drawText(300,1600, "Nom: ");
           painter.drawText(300, 2400, "Prenom: ");
           painter.drawText(300, 3200,"Sexe: ");
           painter.drawText(300,4000,"Type: ");
           painter.drawText(300,4800,"Num tel: ");
           painter.drawText(300,5600,"Cin: ");
           painter.drawText(300,6400,"Email: ");
           painter.setPen(Qt::blue);
           painter.drawText(2100, 800, idS);
           painter.drawText(2100,1600 , this->Nom);
           painter.drawText(2100, 2400, this->Prenom);
           painter.drawText(2100, 3200, this->Sexe);
           painter.drawText(2100, 4000, this->Type);
           painter.drawText(2100, 4800, Num_telS);
           painter.drawText(2100, 5600, CinS);
           painter.drawText(2100, 6400, this->Email);
           painter.end();
           msgBox.setIcon(QMessageBox::Information);
           msgBox.setText("A pdf has been created.");
           msgBox.exec();
}



