#include "historique.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include <QString>
#include <QObject>
#include<QDate>
Historique::Historique()
{

}
Historique::Historique(QString operation, int id){
    this->operation=operation;
    this->id=id;
}



void Historique::Ajouter()
{
    QSqlQuery query;
    query.prepare("insert into HISTORIQUE values (HISTORIQUE_SEQ.nextval, sysdate, :operation, :n_empl);");
    query.bindValue(":operation",operation);
    query.bindValue(":n_empl",id);
    query.exec();
}
QSqlQueryModel * Historique::Afficher()
{
  QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select ID_EMP, DATE_HIS, TYPE_HIS FROM HISTORIQUE;");
       model->setHeaderData(0, Qt::Horizontal,QObject:: tr("ID Employee"));
       model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Date opération"));
       model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Type opération"));
 return model;
}
