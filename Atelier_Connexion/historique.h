#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Historique
{
public:
    Historique();

    Historique(QString, int id);
    void Ajouter();
    QSqlQueryModel * Afficher();
private:
    QString operation;
    int id;
};

#endif // HISTORIQUE_H
