#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString>
#include <QSqlQueryModel>
class Produit
{
public:
    Produit();
    Produit(int,QString,QString,int,QString);
    int getid();
    QString getnom();
    QString getimage();
    int getprix();
    QString getdesc();

    void setid(int);
    void setnom(QString);
    void setimage(QString);
    void setprix(int);
    void setdesc(QString);
    bool ajouter();
    bool modifier();
    QSqlQueryModel* afficher();

    bool supprimer(int);
    QSqlQueryModel * Tridecroi();
    QSqlQueryModel * Tricroi();

private:
    int ID,PRIX;
    QString NOM,DESCRIPTION,IMAGE;
};

#endif // PRODUIT_H
