#ifndef HISTORIQUECLIENTS_H
#define HISTORIQUECLIENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class HistoriqueClients
{
public:
    HistoriqueClients();
    HistoriqueClients(QString, int);
    void Ajouter();
    QSqlQueryModel * Afficher();
private:
    QString operation;
    int id;
};

#endif // HISTORIQUECLIENTS_H
