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
///////////////////////////////////////////////////

void Produit::printPDF()
{

    QPdfWriter pdf("C:/Users/Hp/Desktop/Nouveau dossier/produit.pdf");
    QPainter painter(&pdf);
    QFont font=painter.font();
    QMessageBox msgBox;
    QString id = QString::number(ID);
    QString prix = QString::number(PRIX);
       font.setPointSize(font.pointSize() * 2);
       painter.setFont(font);
       painter.setPen(Qt::black);
       painter.drawText(300,800 , "Identifiant: ");
       painter.drawText(300,3200, "Nom: ");
       painter.drawText(300, 1600, "Image: ");
       painter.drawText(300,4000,"Prix: ");
       painter.drawText(300,4800,"Description: ");
       painter.setPen(Qt::blue);
       painter.drawText(2500, 800, id);
       painter.drawText(2500, 4000, prix);

       painter.drawText(2500, 1600, this->NOM);
       painter.drawText(2500, 3200, this->IMAGE);
       painter.drawText(2500,4800,this->DESCRIPTION);
       painter.end();
       msgBox.setIcon(QMessageBox::Information);
       msgBox.setText("A pdf has been created.");
       msgBox.exec();


}

////////////////////////////////////////////////////////////////////

void Produit::stat(QCustomPlot *customPlot)
{
    QSqlQuery query,query1;
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(156, 212, 114));
    gradient.setColorAt(0.38, QColor(191, 234, 170));
    gradient.setColorAt(1, QColor(212, 236, 201));
    customPlot->clearPlottables();
    customPlot->clearGraphs();
    customPlot->replot();

    customPlot->setBackground(QBrush(gradient));


    QCPBars *fossil = new QCPBars(customPlot->xAxis, customPlot->yAxis);

    fossil->setAntialiased(false);

    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("statistique selon le type");
    fossil->setPen(QPen(QColor(125,198, 209).lighter(170)));
    fossil->setBrush(QColor(125,198, 209));

    QVector<double> ticks;
    QVector<QString> labels;
    query.prepare("SELECT COUNT(DISTINCT numc) FROM contrats where typec='location'");
    query.exec();
    int un;
    while(query.next())
    {
        un=query.value(0).toInt();
        qDebug()<<un;
    }

    query.prepare("SELECT COUNT(DISTINCT numc) FROM contrats where typec='vendre'");
    query.exec();
    int deux;
    while(query.next())
    {
        deux=query.value(0).toInt();
    }
/*
    query.prepare("SELECT COUNT(DISTINCT numc) FROM contrats where MONTANT between 10000 and 100000");
    query.exec();
    int trois;
    while(query.next())
    {
        trois=query.value(0).toInt();
    }

*/



    ticks << 1 << 2  ;
    labels << "location" << "vendre"  ;
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    customPlot->xAxis->setTicker(textTicker);
    customPlot->xAxis->setTickLabelRotation(60);
    customPlot->xAxis->setSubTicks(false);
    customPlot->xAxis->setTickLength(0, 4);
    customPlot->xAxis->setRange(0, 8);
    customPlot->xAxis->setBasePen(QPen(Qt::black));
    customPlot->xAxis->setTickPen(QPen(Qt::white));
    customPlot->xAxis->grid()->setVisible(true);
    customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    customPlot->xAxis->setTickLabelColor(Qt::black);
    customPlot->xAxis->setLabelColor(Qt::green);

    // prepare y axis:
    customPlot->yAxis->setRange(0, 20);
    customPlot->yAxis->setPadding(5); // a bit more space to the left border
    customPlot->yAxis->setLabel("Nombre de contrats");
    customPlot->yAxis->setBasePen(QPen(Qt::black));
    customPlot->yAxis->setTickPen(QPen(Qt::black));
    customPlot->yAxis->setSubTickPen(QPen(Qt::black));
    customPlot->yAxis->grid()->setSubGridVisible(true);
    customPlot->yAxis->setTickLabelColor(Qt::black);
    customPlot->yAxis->setLabelColor(Qt::black);
    customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData  << un <<deux  ;
   // nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
  //  nuclear->setData(ticks, nuclearData);
 //   regen->setData(ticks, regenData);

    // setup legend:
    customPlot->legend->setVisible(true);
    customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = QFont();
    legendFont.setPointSize(10);
    customPlot->legend->setFont(legendFont);
    customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}
