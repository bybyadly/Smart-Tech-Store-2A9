#include "fournisseur.h"
#include <QPdfWriter>
#include<QPainter>
#include <QMessageBox>
fournisseur::fournisseur(){

}
fournisseur::fournisseur(int id, QString nom, QString categorie, QString adresse , QString email){
    this->id=id;
    this->nom=nom;
    this->categorie=categorie;
    this->adresse=adresse;
    this->email=email;
}
bool fournisseur::ajouter(){
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("insert into FOURNISSEUR (id,nom,categorie,adresse,email)"
                  "values (:id, :nom, :categorie, :adresse, :email)");
    query.bindValue(":id",id);
    query.bindValue(":nom", nom);
    query.bindValue(":categorie", categorie);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);

    return query.exec();
}
QSqlQueryModel * fournisseur::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("select * from fournisseur");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("email"));

    return model;
}
bool fournisseur::supprimer(int id){
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("delete from fournisseur where ID = :id");
    query.bindValue(":id", res);
    return query.exec();
}

bool fournisseur::modifier(){



    QSqlQuery query;
    QString id_string=QString::number(id);


         query.prepare("UPDATE FOURNISSEUR  set id= :newID, nom= :newnom,  categorie= :newcategorie, adresse= :newadresse ,email=:newemail WHERE  id= :newID");

         query.bindValue(":newID", id_string);
         query.bindValue(":newnom", nom);
         query.bindValue(":newcategorie", categorie);
         query.bindValue(":newadresse", adresse);
         query.bindValue(":newemail", email);
         ;
      return   query.exec();
}
QSqlQueryModel* fournisseur::trier(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur order by id");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("adresse"));

    return model;
}
QSqlQueryModel* fournisseur::trierNom(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur order by nom");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("adresse"));

    return model;
}
QSqlQueryModel* fournisseur::chercher(QString field){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEUR where id || nom LIKE '%"+field+"%' ");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("categorie"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("adresse"));

    return model;



}
void fournisseur::printPDF_fournisseur()
{

    QPdfWriter pdf("C:/Users/Hp/Desktop/testinteg/Smart-Tech-Store-2A9/Atelier_Connexion/fournisseur.pdf");
    QPainter painter(&pdf);
    QFont font=painter.font();
    QMessageBox msgBox;
       font.setPointSize(font.pointSize() * 2);
       painter.setFont(font);
       painter.setPen(Qt::blue);
       painter.drawText(3000,400 , "fournisseur: ");
       painter.setPen(Qt::black);
       painter.drawText(300,800 , "id_fournisseur: ");
       painter.drawText(300,1600, "nom_fournisseur: ");
       painter.drawText(300, 2400, "categorie: ");
       painter.drawText(300, 3200, "adresse: ");
       painter.drawText(300,4000,"email_fournisseur: ");
       painter.setPen(Qt::blue);
       QString res = QString::number(id);
       painter.drawText(2500, 800, res);
       painter.drawText(2500, 1600, this->nom);
       painter.drawText(2500, 2400, this->categorie);
       painter.drawText(2500, 3200, this->adresse);
       painter.drawText(2500,4000,this->email);
       painter.end();
       msgBox.setIcon(QMessageBox::Information);
       msgBox.setText("A pdf has been created.");
       msgBox.exec();


}
//////////////////////////////////////////////////////
bool fournisseur::supprimerfour()
{

    QSqlQuery query;


    query.prepare("Delete from FOURNISSEUR" );



 return   query.exec();

}
