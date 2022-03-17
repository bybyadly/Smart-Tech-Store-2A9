#include "clients.h"

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
    query.bindValue(":Cin", Cin);
    query.bindValue(":Num_tel", Num_tel);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":Email", Email);
    query.bindValue(":Sexe", Sexe);
    query.bindValue(":Type", Type);
    return query.exec();
}
