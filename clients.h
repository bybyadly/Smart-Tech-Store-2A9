#ifndef CLIENTS_H
#define CLIENTS_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Clients
{
    int ID, Cin, Num_tel;
    QString Nom, Prenom, Email, Sexe, Type;
public:
    Clients();
    Clients(int , int , int , QString  , QString , QString , QString, QString );
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
};

#endif // CLIENTS_H
