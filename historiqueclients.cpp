#include "historiqueclients.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include <QString>
#include <QObject>
#include<QDate>
HistoriqueClients::HistoriqueClients()
{

}
HistoriqueClients::HistoriqueClients(QString operation, int id)
{
    this->operation=operation;
    this->id=id;
}
void HistoriqueClients::Ajouter()
{
    QSqlQuery query;
    query.prepare("insert into HISTORIQUE_CLIENTS values (HISTORIQUE_CLIENTS_SEQ.nextval, sysdate, :operation, :n_client);");
    query.bindValue(":operation",operation);
    query.bindValue(":n_client",id);
    query.exec();
}
QSqlQueryModel * HistoriqueClients::Afficher()
{
  QSqlQueryModel * model= new QSqlQueryModel();
       model->setQuery("select DATE_HIST, TYPE_OPERATION, id_client FROM HISTORIQUE_CLIENTS;");
       model->setHeaderData(0, Qt::Horizontal,QObject:: tr("Date"));
       model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Type d'opération"));
       model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Numéro Client"));
 return model;
}
