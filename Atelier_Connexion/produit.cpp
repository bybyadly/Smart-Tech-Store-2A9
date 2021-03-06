#include "produit.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>



Produit::Produit()
{
    ID=0;
    PRIX=0;
    QUANTITE=0;
    NOM=" ";
    IMAGE=" ";
    DESCRIPTION=" ";

}

Produit::Produit(int ID,QString NOM,QString IMAGE,int PRIX ,QString DESCRIPTION,int QUANTITE)
{


    this->ID=ID;
    this->QUANTITE=QUANTITE;
    this->NOM=NOM;
    this->IMAGE=IMAGE;
    this->PRIX=PRIX;
    this->DESCRIPTION=DESCRIPTION;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int Produit::getid()
{

    return ID;
}

int Produit::getqtte()
{

    return QUANTITE;
}
QString Produit::getnom()
{
    return NOM;

}
QString Produit::getimage()
{
    return IMAGE;

}
int Produit::getprix()
{
    return PRIX;

}
QString Produit::getdesc()
{
    return DESCRIPTION;

}

void Produit::setid(int a)
{
    ID=a;

}
void Produit::setnom(QString a)
{
    NOM=a;

}
void Produit::setimage(QString a)
{
    IMAGE=a;

}
void Produit::setprix(int a)
{
    PRIX=a;

}
void Produit::setdesc(QString a)
{
    DESCRIPTION=a;

}
/////////////////////////////////////////////////////////////////////////////

bool Produit::ajouter()
{

   QSqlQuery query;
   QString id_string=QString::number(ID);
   QString prix_string=QString::number(PRIX);
   QString qtte_string=QString::number(QUANTITE);

        query.prepare("INSERT INTO PRODUITS (ID, IMAGE, NOM ,PRIX ,DESCRIPTION ,QUANTITE) "
                      "VALUES (:ID, :IMAGE, :NOM, :PRIX, :DESCRIPTION, :QUANTITE)");

        query.bindValue(":ID", id_string);
        query.bindValue(":IMAGE", IMAGE);
        query.bindValue(":NOM", NOM);
        query.bindValue(":PRIX", prix_string);
        query.bindValue(":DESCRIPTION", DESCRIPTION);
        query.bindValue(":QUANTITE", qtte_string);
     return   query.exec();
}

///////////////////////////////////////////////////////////////////////////////////////////

QSqlQueryModel* Produit::afficher()
{QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUITS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Image"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Description"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("QUANTITE"));
    return model;
}
////////////////////////////////////////////////////////////////////////////////////////////

bool Produit::modifier()
{

   QSqlQuery query;
   QString id_string=QString::number(ID);
   QString prix_string=QString::number(PRIX);
   QString qtte_string=QString::number(QUANTITE);

        query.prepare("UPDATE PRODUITS  set ID= :newID, IMAGE= :newIMAGE, NOM= :newNOM, PRIX= :newPRIX, DESCRIPTION= :newDESC ,QUANTITE=:newQTTE  WHERE  ID= :newID");

        query.bindValue(":newID", id_string);
        query.bindValue(":newIMAGE", IMAGE);
        query.bindValue(":newNOM", NOM);
        query.bindValue(":newPRIX", prix_string);
        query.bindValue(":newDESC", DESCRIPTION);
        query.bindValue(":newQTTE", qtte_string);
     return   query.exec();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
bool Produit::supprimer(int id)
{

    QSqlQuery query;


    query.prepare("Delete from PRODUITS where id=:ID");

    query.bindValue(":ID", id);

 return   query.exec();

}
///////////////////////////////////////////////////////////////////////////////////////////////////////


////
///////////////////////////////////////////////////////////////////////////////////////////////////////
QSqlQueryModel * Produit::Tridecroi()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Produits order by ID desc"  );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Image"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Description"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("QUANTITE"));
    return model;

}
/////////////////////////////////////////////////////////////////////////////////////////////////////
QSqlQueryModel * Produit::Tricroi()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Produits order by ID "  );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Image"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Description"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("QUANTITE"));
    return model;

}

/////////////////////////////////////////
QSqlQueryModel * Produit::recherche(QString rech)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Produits where ID || NOM LIKE '%"+rech+"%'"  );

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Image"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Description"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("QUANTITE"));
    return model;
}
///////////////////////////////////////////////////

void Produit::printPDF()
{

    QPdfWriter pdf("C:/Users/Hp/Desktop/Nouveau dossier/produit.pdf");
    QPainter painter(&pdf);
    QFont font=painter.font();
    QMessageBox msgBox;
    QString id = QString::number(ID);
    QString prix = QString::number(PRIX);
    QString quantite = QString::number(QUANTITE);
       font.setPointSize(font.pointSize() * 2);
       painter.setFont(font);
       painter.setPen(Qt::black);
       painter.drawText(300,800 , "Identifiant: ");
       painter.drawText(300,3200, "Nom: ");
       painter.drawText(300, 1600, "Image: ");
       painter.drawText(300,4000,"Prix: ");
       painter.drawText(300,4800,"Description: ");
       painter.drawText(300,5400,"Quantite: ");
       painter.setPen(Qt::blue);
       painter.drawText(2500, 800, id);
       painter.drawText(2500, 4000, prix);
       painter.drawText(2500, 5400, quantite);

       painter.drawText(2500, 1600, this->NOM);
       painter.drawText(2500, 3200, this->IMAGE);
       painter.drawText(2500,4800,this->DESCRIPTION);
       painter.end();
       msgBox.setIcon(QMessageBox::Information);
       msgBox.setText("A pdf has been created.");
       msgBox.exec();


}

////////////////////////////////////////////////////////////////////

bool Produit::verif(int id)
{

    QSqlQuery query;
    bool test=true;
    int n=getqtte();


    query.prepare("select QUANTITE from PRODUITS where id=:ID ");

    if (n<10)
    {test=false;}



    query.bindValue(":ID", id);

 return   query.exec();

}
