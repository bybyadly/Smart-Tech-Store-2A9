#include "azizwindow.h"
#include "ui_azizwindow.h"
#include <QString>
#include "clients.h"
#include <QMessageBox>
#include "historiqueclients.h"
#include <QSqlError>
#include <QUrl>
#include <QDesktopServices>

#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextStream>

#include "arduinoaziz.h"
#include <QtSerialPort/QSerialPort>
#include <QUrl>
 #include <QDesktopServices>


azizwindow::azizwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::azizwindow)
{

    ui->setupUi(this);
    ui->tableViewAffichuer->setModel(CL.afficher());
    ui->tableViewHistorique->setModel(Hist.Afficher());


    int ret=A.connect_arduino(); // lancer la connexion à arduino; // lancer la connexion à arduino
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

azizwindow::~azizwindow()
{
    delete ui;
}



void azizwindow::on_pushButton_Ajouter_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    int Cin = ui->lineEdit_Cin->text().toUInt();
    int Num_tel = ui->lineEdit_TEL->text().toUInt();
    QString Nom = ui->lineEdit_Nom->text();
    QString Prenom = ui->lineEdit_Prenom->text();
    QString Email = ui->lineEdit_Email->text();
    QString Type;
    QString Sexe;
    if (ui->Homme->isChecked()){
        Sexe = "Homme";
    }
    if (ui->Femme->isChecked()){
        Sexe = "Femme";
    }
    if (ui->Passage->isChecked()){
        Type = "Passage";
    }
    if (ui->Fidele->isChecked()){
        Type = "Fidele";
    }
    Clients C (id, Cin, Num_tel, Nom, Prenom, Email, Sexe, Type);

    bool test = C.ajouter();

    if (test){
        QString operation = "Ajout";
        historiqueClients H(operation, id);
        H.Ajouter();
        ui->tableViewHistorique->setModel(H.Afficher());
        ui->tableViewAffichuer->setModel(CL.afficher());
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

void azizwindow::on_pushButton_Suppression_clicked()
{
    int id = ui->lineEdit_ID_Supression->text().toInt();
    bool test = CL.supprimer(id);

    if (test){
        QString operation = "Suppression";
        historiqueClients H(operation, id);
        H.Ajouter();
        ui->tableViewHistorique->setModel(H.Afficher());
        ui->tableViewAffichuer->setModel(CL.afficher());
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                              QObject::tr("Suppression effectué"),
                              QMessageBox::Ok
                              );
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Suppression non effectué"),
                              QMessageBox::Cancel
                              );
    }
}

void azizwindow::on_pushButton_Modifer_clicked()
{
    int id = ui->lineEdit_ID->text().toInt();
    int Cin = ui->lineEdit_Cin->text().toUInt();
    int Num_tel = ui->lineEdit_TEL->text().toUInt();
    QString Nom = ui->lineEdit_Nom->text();
    QString Prenom = ui->lineEdit_Prenom->text();
    QString Email = ui->lineEdit_Email->text();
    QString Type;
    QString Sexe;
    if (ui->Homme->isChecked()){
        Sexe = "Homme";
    }
    if (ui->Femme->isChecked()){
        Sexe = "Femme";
    }
    if (ui->Passage->isChecked()){
        Type = "Passage";
    }
    if (ui->Fidele->isChecked()){
        Type = "Fidele";
    }
    Clients C (id, Cin, Num_tel, Nom, Prenom, Email, Sexe, Type);

    bool test = C.modifier();

    if (test){QString operation = "Modification";
        historiqueClients H(operation, id);
        H.Ajouter();
        ui->tableViewHistorique->setModel(H.Afficher());
        ui->tableViewAffichuer->setModel(CL.afficher());
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

void azizwindow::on_pushButton_trier_clicked()
{
    ui->tableViewAffichuer->setModel(CL.trier());

}

void azizwindow::on_pushButton_Rechercher_clicked()
{
    QString reach_filed = ui->lineEdit_nom_chercher->text();
    ui->tableViewAffichuer->setModel(CL.rechercher(reach_filed));
}

void azizwindow::on_pushButton_actualiser_clicked()
{
    ui->tableViewAffichuer->setModel(CL.afficher());
}

void azizwindow::on_pushButtonActualiserHistorique_clicked()
{
    ui->tableViewHistorique->setModel(Hist.Afficher());
}

void azizwindow::on_pushButtonGenerePDF_clicked()
{
    QString val=ui->lineEdit_ID_PDF->text();
    QSqlQuery query;
       query.prepare("select * from Clients where (id_client) LIKE "+val+" ");
       int id, cin , Num_tel;
       QString Nom, Prenom, Email, Sexe, Type;
       if (query.exec()){
           while (query.next()){
               id= query.value(0).toInt();
               Nom = query.value(1).toString();
               Prenom = query.value(2).toString();
               Email = query.value(3).toString();
               cin= query.value(4).toInt();
               Sexe = query.value(5).toString();
               Num_tel= query.value(6).toInt();
               Type = query.value(7).toString();
}
           }else{
           QMessageBox::critical(this, tr("Error::"), query.lastError().text());
       }
    Clients C(id, cin, Num_tel, Nom, Prenom, Email, Sexe, Type);
    C.printPDF_comptes();

}

void azizwindow::on_pushButton_AfficherPDF_clicked()
{
    QString link="file:///C:/Users/Aziz Abrougui/Documents/generated_pdf_client.pdf";
                QDesktopServices::openUrl(QUrl(link));
}

void azizwindow::on_pushButton_stat_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
                QSqlQueryModel * model= new QSqlQueryModel();
                model->setQuery("select * from Clients where id_client < 10 ");
                float taille=model->rowCount();
                model->setQuery("select * from Clients where id_client  between 10 and 100 ");
                float taillee=model->rowCount();
                model->setQuery("select * from Clients where id_client >200 ");
                float tailleee=model->rowCount();
                float total=taille+taillee+tailleee;
                QString a=QString("client fidele . "+QString::number((taille*100)/total,'f',2)+"%" );
                QString b=QString("Client passage .  "+QString::number((taillee*100)/total,'f',2)+"%" );
                QString c=QString("super Clients."+QString::number((tailleee*100)/total,'f',2)+"%" );
                QPieSeries * series = new QPieSeries();
                series->append(a,taille);
                series->append(b,taillee);
                series->append(c,tailleee);
                if (taille!=0)
                {QPieSlice *slice = series->slices().at(0);
                    slice->setLabelVisible();
                    slice->setPen(QPen());}
                if ( taillee!=0)
                {
                    // Add label, explode and define brush for 2nd slice
                    QPieSlice *slice1 = series->slices().at(1);
                    //slice1->setExploded();
                    slice1->setLabelVisible();
                }
                if(tailleee!=0)
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
                chart->setTitle("distribution clients :Nombre Des clients "+ QString::number(total));
                chart->legend()->hide();
                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();
    }


void azizwindow::on_pushButton_imprimer_clicked()
{
    QString strStream;

                         QTextStream out(&strStream);

                         const int rowCount = ui->tableViewAffichuer->model()->rowCount();
                         const int columnCount = ui->tableViewAffichuer->model()->columnCount();
                         QString TT = QDateTime::currentDateTime().toString();
                         out <<"<html>\n"
                               "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             << "<title>ERP - COMmANDE LIST<title>\n "
                             << "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                                +"<img src=file:C:\\Users\\Aziz Abrougui\\Documents\\generated_pdf_client.pdf />"
                                "<h1 style=\"text-align: center;\"><strong> ****LISTE DES  licence commerciale **** </strong></h1>"


                             "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                               "</br> </br>";
                         // headers
                         out << "<thead><tr bgcolor=#d6e5ff>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tableViewAffichuer->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tableViewAffichuer->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tableViewAffichuer->isColumnHidden(column)) {
                                     QString data =ui->tableViewAffichuer->model()->data(ui->tableViewAffichuer->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);

                         QPrinter printer;

                         QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                         if (dialog->exec() == QDialog::Accepted) {
                             document->print(&printer);
                         }

                         delete document;
}

void azizwindow::on_pushButton_sombre_clicked()
{
    QFile styleSheetFile("C:/Users/Aziz Abrougui/Desktop/copie stat imprimer/Combinear.qss");
            styleSheetFile.open(QFile::ReadOnly);
            QString styleSheet = QLatin1String (styleSheetFile.readAll());
            azizwindow::setStyleSheet(styleSheet);
}

void azizwindow::on_pushButton_blanc_clicked()
{
            QFile styleSheetFile("C:/Users/Aziz Abrougui/Desktop/copie stat imprimer/Integrid.qss");
            styleSheetFile.open(QFile::ReadOnly);
            QString styleSheet = QLatin1String (styleSheetFile.readAll());
           azizwindow::setStyleSheet(styleSheet);
}

void azizwindow::on_pushButton_trier_nom_clicked()
{
    ui->tableViewAffichuer->setModel(CL.trierNom());
}

/////////////////////////////////////////////////////////////////
void azizwindow::on_pushButton_2_clicked() /*///////alarme/////*/
{
      A.write_to_arduino("a");
}

void azizwindow::on_ouvrir_clicked()  //ouvrir caisse
{
    QString var;
        QString nom = ui->lineEdit_caisse->text();
        qDebug() << nom;

    QSqlQuery querry;
    querry.prepare("Select NOM from EMPLOYE where ID_E like '"+nom+"' ");
    if (querry.exec()){
        while (querry.next()){
            qDebug() << "fonded " << querry.value(0).toString();
            var = querry.value(0).toString();
        }
    }else{
        qDebug() << "Error";
    }
    if(nom=="DC 1E F2 38") //samsung
    {

    A.write_to_arduino("r");

    }
    else if (nom=="43 6F B8 19") //apple
    {
        A.write_to_arduino("s");
    }
    else
    {
        A.write_to_arduino("m");
    }

    /*if (ui->lineEdit_caisse->text()=="DC 1E F2 38")
         { A.write_to_arduino("r");}
         else if (ui->lineEdit_caisse->text()=="43 6F B8 19")
             { A.write_to_arduino("s");}

        else {
            A.write_to_arduino("m");
        }*/
}
