#include "produit.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Produit::Produit()
{
    ID=0;
    PRIX=0;
    NOM=" ";
    IMAGE=" ";
    DESCRIPTION=" ";

}

Produit::Produit(int ID,QString NOM,QString IMAGE,int PRIX ,QString DESCRIPTION)
{


    this->ID=ID;
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

        query.prepare("INSERT INTO PRODUITS (ID, IMAGE, NOM ,PRIX ,DESCRIPTION) "
                      "VALUES (:ID, :IMAGE, :NOM, :PRIX, :DESCRIPTION)");

        query.bindValue(":ID", id_string);
        query.bindValue(":IMAGE", IMAGE);
        query.bindValue(":NOM", NOM);
        query.bindValue(":PRIX", prix_string);
        query.bindValue(":DESCRIPTION", DESCRIPTION);
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
    return model;
}
////////////////////////////////////////////////////////////////////////////////////////////

bool Produit::modifier()
{

   QSqlQuery query;
   QString id_string=QString::number(ID);
   QString prix_string=QString::number(PRIX);

        query.prepare("UPDATE PRODUITS  set ID= :newID, IMAGE= :newIMAGE, NOM= :newNOM, PRIX= :newPRIX, DESCRIPTION= :newDESC  WHERE  ID= :newID");

        query.bindValue(":newID", id_string);
        query.bindValue(":newIMAGE", IMAGE);
        query.bindValue(":newNOM", NOM);
        query.bindValue(":newPRIX", prix_string);
        query.bindValue(":newDESC", DESCRIPTION);
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
    return model;

}

/////////////////////////////////////////
QSqlQueryModel * Produit::recherche(QString rech)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Produits where ID LIKE '%"+rech+"%'"  );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Image"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Description"));
    return model;
}
