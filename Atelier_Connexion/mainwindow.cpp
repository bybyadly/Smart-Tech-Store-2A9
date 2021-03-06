#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtCharts>
#include <QPieSlice>
#include <QSqlQuery>
#include <QPieSeries>
#include <QRegExpValidator>
#include"menu.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFile styleSheetFile("C:/Users/Hp/Desktop/gittt/Smart-Tech-Store-2A9/Atelier_Connexion/Perstfic.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    MainWindow::setStyleSheet(styleSheet);






    ui->setupUi(this);
    ui->tab_produits->setModel(Pro.afficher());
    ui->le_id->setValidator(new QIntValidator(0,999999,this));
    ui->le_prix->setValidator(new QIntValidator(0,99999,this));
    ui->qtte->setValidator(new QIntValidator(0,99999,this));

    ui->tab_produits->setModel(Pro.afficher());
    ui->new_id->setValidator(new QIntValidator(0,99999,this));
    ui->newprix->setValidator(new QIntValidator(0,99999,this));
    ui->newqtte->setValidator(new QIntValidator(0,99999,this));

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int PRIX=ui->le_prix->text().toInt();
    int ID=ui->le_id->text().toInt();
    int QUANTITE=ui->qtte->text().toInt();
    QString NOM=ui->le_nom->text();
    QString IMAGE=ui->la_image->text();
    QString DESCRIPTION=ui->la_description->text();

   Produit P(ID,IMAGE,NOM,PRIX,DESCRIPTION,QUANTITE);
   bool test = P.ajouter();
   if (test){
           ui->tab_produits->setModel(Pro.afficher());
           QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Ajout effectué"),
                                 QMessageBox::Ok
                                 );
       }else{
           QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                                 QObject::tr("Ajouter non effectué"),
                                 QMessageBox::Cancel
                                 );
       }

}



void MainWindow::on_pb_supprimer_clicked()
{
    Produit p1;

    p1.setid(ui->le_id_sup->text().toInt());
    bool test=p1.supprimer(p1.getid());
    QMessageBox msgbox;

    if (test){
            ui->tab_produits->setModel(Pro.afficher());
            QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                  QObject::tr("Suppression effectuée"),
                                  QMessageBox::Ok
                                  );
        }else{
            QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                                  QObject::tr("Suppression non effectuée"),
                                  QMessageBox::Cancel
                                  );
        }
}

void MainWindow::on_pb_afficher_clicked()
{
    ui->tab_produits->setModel(Pro.afficher());
}

void MainWindow::on_pb_exit_clicked()
{
    exit(EXIT_FAILURE);
}

void MainWindow::on_pb_modifier_clicked()
{
    int newPRIX=ui->newprix->text().toInt();
    int newID=ui->new_id->text().toInt();
    int newQTTE=ui->newqtte->text().toInt();
    QString newNOM=ui->newname->text();
    QString newIMAGE=ui->newimage->text();
    QString newDESC=ui->newdesc->text();

   Produit P(newID,newIMAGE,newNOM,newPRIX,newDESC,newQTTE);

   bool test = P.modifier();
   if (test){
           ui->tab_produits->setModel(Pro.afficher());
           QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                 QObject::tr("Modification effectuée"),
                                 QMessageBox::Ok
                                 );
       }else{
           QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                                 QObject::tr("Modification non effectuée"),
                                 QMessageBox::Cancel
                                 );
       }
}

void MainWindow::on_pb_tridecroi_clicked()
{
         ui->tab_produits->setModel(Pro.Tridecroi());

}

void MainWindow::on_pb_tricroi_clicked()
{
    ui->tab_produits->setModel(Pro.Tricroi());
}



void MainWindow::on_pb_rechercher_clicked()
{
    QString rech= ui->recherche->text();

        ui->tab_produits->setModel(Pro.recherche(rech));
}

void MainWindow::on_pb_pdf_clicked()
{



     int PRIX=ui->le_prix->text().toInt();
     int ID=ui->le_id->text().toInt();
     int QUANTITE=ui->qtte->text().toInt();
     QString NOM=ui->le_nom->text();
     QString IMAGE=ui->la_image->text();
     QString DESCRIPTION=ui->la_description->text();

    Produit P(ID,IMAGE,NOM,PRIX,DESCRIPTION,QUANTITE);
    P.printPDF();
}

void MainWindow::on_pb_stats_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                      model->setQuery("select * from Produits where PRIX < 10 ");
                      float PRIX1=model->rowCount();
                      model->setQuery("select * from Produits where PRIX  between 10 and 20 ");
                      float PRIX2=model->rowCount();
                      model->setQuery("select * from Produits where PRIX >20 ");
                      float PRIX3=model->rowCount();
                      float total=PRIX1+PRIX2+PRIX3;
                      QString a=QString("inferieur a 10  "+QString::number((PRIX1*100)/total,'f',2)+"%" );
                      QString b=QString("entre 10 et 20  "+QString::number((PRIX2*100)/total,'f',2)+"%" );
                      QString c=QString("+20  "+QString::number((PRIX3*100)/total,'f',2)+"%" );
                      QPieSeries *series = new QPieSeries();
                      series->append(a,PRIX1);
                      series->append(b,PRIX2);
                      series->append(c,PRIX3);
              if (PRIX1!=0)
              {QPieSlice *slice = series->slices().at(0);
               slice->setLabelVisible();
               slice->setPen(QPen());}
              if ( PRIX2!=0)
              {
                       // Add label, explode and define brush for 2nd slice
                       QPieSlice *slice1 = series->slices().at(1);
                       //slice1->setExploded();
                       slice1->setLabelVisible();
              }
              if(PRIX3!=0)
              {
                       // Add labels to rest of slices
                       QPieSlice *slice2 = series->slices().at(2);
                       //slice1->setExploded();
                       slice2->setLabelVisible();
              }
                      // Create the chart widget
                      QChart *chart = new QChart();
                      // Add data to chart with title and hide legend
                      chart->addSeries(series);
                      chart->setTitle("Pourcentage Par prix :Nombre de Produits disponibles "+ QString::number(total));
                      chart->legend()->hide();
                      // Used to display the chart
                      QChartView *chartView = new QChartView(chart);
                      chartView->setRenderHint(QPainter::Antialiasing);
                      chartView->resize(1000,500);
                      chartView->show();
}

void MainWindow::on_pb_verif_clicked()
{
    Produit p1;
QString idA = ui->verifid->text();
int qnt;
bool test;
QSqlQuery qry;
qry.prepare("select QUANTITE from PRODUITS where id = "+idA+" ");
if (qry.exec()){
    while (qry.next()){
        qnt = (qry.value(0).toInt());
        if (qnt >= 2){
            test = true;
        }else{
            test = false;
        }
    }
}
    QMessageBox msgbox;
    if (test){
            ui->tab_produits->setModel(Pro.afficher());
            QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                  QObject::tr("Ce Produit est encore en stock"),
                                  QMessageBox::Ok
                                  );
        }else{
            QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                                  QObject::tr("Ce Produit nest plus en stock"),
                                  QMessageBox::Cancel
                                  );
        }
}

//////////////////////////////////////////////////////////////////////////////////////


void MainWindow::on_Dark_clicked()
{
    QFile styleSheetFile("C:/Users/Hp/Desktop/gittt/Smart-Tech-Store-2A9/Atelier_Connexion/Diffnes.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    MainWindow::setStyleSheet(styleSheet);
}

void MainWindow::on_Light_clicked()
{
    QFile styleSheetFile("C:/Users/Hp/Desktop/gittt/Smart-Tech-Store-2A9/Atelier_Connexion/Integrid.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    MainWindow::setStyleSheet(styleSheet);
}
////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_open_clicked()
{
    A.write_to_arduino("1");
}

void MainWindow::on_closed_clicked()
{
    A.write_to_arduino("0");
}

void MainWindow::update_label()
{
    data=A.read_from_arduino();
     ui->nb_slots->append(data);

    if(data=="1")

        ui->etat_porte->setText("Une voiture est entrée au parking"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->etat_porte->setText("Une voiture est sortie du parking");

    // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON



}



void MainWindow::on_pushButton_clicked()
{
    hide();
   m=new Menu(this);
   m->show();
}
