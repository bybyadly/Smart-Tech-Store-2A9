#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString>
#include <QSqlQueryModel>
class Produit
{

public:
    Produit();
    Produit(int,QString,QString,int,QString,int);
    int getid();
    QString getnom();
    QString getimage();
    int getprix();
    int getqtte();
    QString getdesc();

    void setid(int);
    void setnom(QString);
    void setimage(QString);
    void setprix(int);
    void setdesc(QString);
    bool ajouter();
    bool modifier();
    QSqlQueryModel* afficher();
QSqlQueryModel * recherche(QString);
    bool supprimer(int);
    bool verif(int);
    QSqlQueryModel * Tridecroi();
    QSqlQueryModel * Tricroi();
    void printPDF();
    bool supprimerprods();

private:
    int ID,PRIX,QUANTITE;
    QString NOM,DESCRIPTION,IMAGE;
};

#endif // PRODUIT_H

