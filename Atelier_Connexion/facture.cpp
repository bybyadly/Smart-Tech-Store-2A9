#include "facture.h"
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>


facture::facture(){

}
facture::facture(int num_facture, int montant, QString produit , QString type , QString datef){
    this->num_facture=num_facture;
    this->produit=produit;
    this->montant=montant;
    this->type=type;
    this->datef=datef;
}
bool facture::ajouter(){
    QSqlQuery query;
    QString res = QString::number(num_facture);
    query.prepare("insert into facture values (:num_facture, :montant, :produit , :type , :datef)");
    query.bindValue(":num_facture",res);
    query.bindValue(":montant", montant);
    query.bindValue(":produit", produit);
    query.bindValue(":type", type);
    query.bindValue(":datef", datef);

    return query.exec();
}
QSqlQueryModel * facture::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from facture");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("num_facture"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("montant"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("produit"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("datef"));
    return model;
}
bool facture::supprimer(int num_facture){
    QSqlQuery query;
    QString res = QString::number(num_facture);
    query.prepare("delete from facture where num_facture = :num_facture");
    query.bindValue(":num_facture", res);
    return query.exec();
}
bool facture::modifier(){
    QSqlQuery query;
    QString res = QString::number(num_facture);
    query.prepare("UPDATE facture SET montant = :montant , produit = :produit , type = :type , datef = :datef WHERE num_facture = :num_facture");
    query.bindValue(":num_facture",res);
    query.bindValue(":montant", montant);
    query.bindValue(":produit", produit);
    query.bindValue(":type", type);
    query.bindValue(":datef", datef);
    return query.exec();
}
QSqlQueryModel * facture::Tridecroi()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from facture order by num_facture desc"  );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num_facture"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("produit"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("datef"));
    return model;

}

QSqlQueryModel * facture::Tricroi()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("select * from facture order by num_facture "  );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num_facture"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("produit"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("datef"));
    return model;
}


QSqlQueryModel * facture::recherche(QString rech)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from facture where num_facture LIKE '%"+rech+"%'"  );
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num_facture"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("produit"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("datef"));
    return model;
}



void facture::printPDF()
{

        QPdfWriter pdf("C:/Users/Utilisateur/Desktop/Nouveau dossier/facture.pdf");
        QPainter painter(&pdf);
        QFont font=painter.font();
        QMessageBox msgBox;
        QString numfacture = QString::number(num_facture);
        QString montantt = QString::number(montant);

           font.setPointSize(font.pointSize() * 2);
           painter.setFont(font);
           painter.setPen(Qt::black);
           painter.drawText(300,800 , "num_facture: ");
           painter.drawText(300,3200, "produit: ");
           painter.drawText(300, 1600, "type: ");
           painter.drawText(300,4000,"montant: ");
           painter.drawText(300,4800,"date: ");
           ;
           painter.setPen(Qt::blue);
           painter.drawText(2500, 800, numfacture);
           painter.drawText(2500, 4000, montantt);


           painter.drawText(2500, 1600, this->produit);
           painter.drawText(2500, 3200, this->type);
           painter.drawText(2500,4800,this->datef);
           painter.end();
           msgBox.setIcon(QMessageBox::Information);
           msgBox.setText("A pdf has been created.");
           msgBox.exec();

}

////////////////////////////////////////////////
bool facture::supprimerfacs()
{

    QSqlQuery query;


    query.prepare("Delete from facture" );



 return   query.exec();

}
