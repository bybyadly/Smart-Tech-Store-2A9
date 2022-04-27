#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class facture
{int montant;
    QString produit , datef , type ;
    int num_facture;
public:
    facture();
    facture(int, int, QString, QString, QString);

    //Getters
    int getnum_facture(){
        return num_facture;
    }
    int getmontant(){
        return montant;
    }
    QString getproduit(){
        return produit;
    }
    QString getdatef(){
        return datef;
    }
    QString gettype(){
        return type;
    }

    //Setters
    void setmontant(int n){
        montant=n;
    }
    void setproduit(QString n){
        produit=n;
    }
    void setnum_facture(int n){
        num_facture=n;
    }
    void setdate(QString d){
        datef=d;
    }
    void settype(QString t){
        type=t ;
    }
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * Tridecroi();
    QSqlQueryModel * Tricroi();
    QSqlQueryModel * recherche(QString);
    void printPDF();
    bool supprimerfacs();
};

#endif // FACTURE_H
