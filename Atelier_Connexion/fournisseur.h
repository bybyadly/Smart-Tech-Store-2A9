#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseur
{QString nom,categorie,adresse,email;
    int id;
public:
    fournisseur();
    fournisseur (int,QString,QString,QString,QString);

    QString getnom() {return nom;}
    QString getcategorie() {return categorie;}
    QString getadresse() {return adresse;}
    QString getemail() {return email;}
    int getID(){return id;}


    void setNom (QString n) {nom=n;}
 void setcategorie (QString c) {categorie=c;}
 void setadresse (QString a) {adresse=a;}
  void setemail (QString e) {email=e;}
  void setId (int id) {this->id=id;}


  bool ajouter();
  QSqlQueryModel * afficher();
  bool supprimer(int);
  bool modifier();
  QSqlQueryModel * trier();
     QSqlQueryModel * trierNom();
     QSqlQueryModel * chercher(QString);
     void printPDF_fournisseur() ;
     bool supprimerfour();
};

#endif // FOURNISSEUR_H
