#include "mainwindow.h"
#include "ui_mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableViewAffichuer->setModel(CL.afficher());
    ui->tableViewHistorique->setModel(Hist.Afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Ajouter_clicked()
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
        HistoriqueClients H(operation, id);
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

void MainWindow::on_pushButton_Suppression_clicked()
{
    int id = ui->lineEdit_ID_Supression->text().toInt();
    bool test = CL.supprimer(id);

    if (test){
        QString operation = "Suppression";
        HistoriqueClients H(operation, id);
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

void MainWindow::on_pushButton_Modifer_clicked()
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
        HistoriqueClients H(operation, id);
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

void MainWindow::on_pushButton_trier_clicked()
{
    ui->tableViewAffichuer->setModel(CL.trier());

}

void MainWindow::on_pushButton_Rechercher_clicked()
{
    QString reach_filed = ui->lineEdit_nom_chercher->text();
    ui->tableViewAffichuer->setModel(CL.rechercher(reach_filed));
}

void MainWindow::on_pushButton_actualiser_clicked()
{
    ui->tableViewAffichuer->setModel(CL.afficher());
}

void MainWindow::on_pushButtonActualiserHistorique_clicked()
{
    ui->tableViewHistorique->setModel(Hist.Afficher());
}

void MainWindow::on_pushButtonGenerePDF_clicked()
{
    QString val=ui->lineEdit_ID_PDF->text();
    QSqlQuery query;
       query.prepare("select * from Clients where (id_client) LIKE "+val+" ");
       int id, Cin, Num_tel;
       QString Nom, Prenom, Email, Sexe, Type;
       if (query.exec()){
           while (query.next()){
               id= query.value(0).toInt();
               Nom = query.value(1).toString();
               Prenom = query.value(2).toString();
               Email = query.value(3).toString();
               Cin= query.value(4).toInt();
               Sexe = query.value(5).toString();
               Num_tel= query.value(6).toInt();
               Type = query.value(7).toString();
}
           }else{
           QMessageBox::critical(this, tr("Error::"), query.lastError().text());
       }
    Clients C(id, Cin, Num_tel, Nom, Prenom, Email, Sexe, Type);
    C.printPDF_comptes();

}

void MainWindow::on_pushButton_AfficherPDF_clicked()
{
    QString link="file:///C:/Users/Aziz Abrougui/Documents/generated_pdf_client.pdf";
                QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_pushButton_stat_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
                QSqlQueryModel * model= new QSqlQueryModel();
                model->setQuery("select * from Clients where id_client < 199 "); // id eli yabdaa bl 100 ela 199
                float taille=model->rowCount();
                model->setQuery("select * from Clients where id_client  between 199 and 299 "); // id mabin 200 ou 299
                float taillee=model->rowCount();
                model->setQuery("select * from Clients where id_client >29999 ");
                float tailleee=model->rowCount();
                float total=taille+taillee+tailleee;
                QString a=QString("client fidele . "+QString::number((taille*100)/total,'f',2)+"%" );
                QString b=QString("Client passage .  "+QString::number((taillee*100)/total,'f',2)+"%" );
                QString c=QString("Clients retsekour ."+QString::number((tailleee*100)/total,'f',2)+"%" );
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


void MainWindow::on_pushButton_imprimer_clicked()
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
