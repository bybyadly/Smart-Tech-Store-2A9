#include "skanderwindow.h"
#include "ui_skanderwindow.h"
#include "facture.h"
#include <QMessageBox>
#include <QtCharts>
#include <QPieSlice>
#include <QSqlQuery>
#include <QPieSeries>
#include "excel.h"
#include "produit.h"
#include "fournisseur.h"
#include "clients.h"




skanderwindow::skanderwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::skanderwindow)
{
    ui->setupUi(this);
    ui->lineEdit_num_facture->setValidator(new QIntValidator (0,99999999,this));
    ui->lineEdit_montant->setValidator(new QIntValidator (0,99999999,this));
  ui->lineEdit_produit->setValidator(new QRegExpValidator (QRegExp("[A-z]*")));
  ui->lineEdit_montant_3->setValidator(new QRegExpValidator (QRegExp("^([0-3][0-9])/[0-1][0-9]/[0-2][0-9][0-9][0-9]$")));


   ui->lineEdit_num_facture_3->setValidator(new QIntValidator (0,99999999,this));
   ui->lineEdit_montant_2->setValidator(new QIntValidator (0,99999999,this));
   ui->lineEdit_produit_2->setValidator(new QRegExpValidator (QRegExp("[A-z]*")));
  ui->lineEdit_montant_4->setValidator(new QRegExpValidator (QRegExp("^([0-3][0-9])/[0-1][0-9]/[0-2][0-9][0-9][0-9]$")));


    ui->tableView->setModel(Et.afficher());
}

skanderwindow::~skanderwindow()
{
    delete ui;
}


void skanderwindow::on_bp_rechercher_clicked()
{
    QString rech= ui->rech->text();
    ui->tableView->setModel(Et.recherche(rech));
}

void skanderwindow::on_pushButton_clicked()
{
    int num_facture = ui->lineEdit_num_facture->text().toInt();
    int montant = ui->lineEdit_montant->text().toInt();
    QString produit = ui->lineEdit_produit->text();
    QString datef = ui->lineEdit_montant_3->text() ;
    QString type ;
    if (ui->radioButton->isChecked())
    {
       type="client" ;
    }
    if (ui->radioButton_2->isChecked())
    {
       type="fournisseur" ;
    }


    facture E(num_facture, montant, produit , type , datef);
    bool test = E.ajouter();

    if (test){
        ui->tableView->setModel(Et.afficher());
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
 //suppression
void skanderwindow::on_pushButton_Supprimer_clicked()
{
    int num_facture = ui->lineEdit_num_facture_2->text().toInt();
    bool test = Et.supprimer(num_facture);

    if (test){
        ui->tableView->setModel(Et.afficher());
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

//modif
void skanderwindow::on_pushButton_2_clicked()
{
    int num_facture = ui->lineEdit_num_facture_3->text().toInt();
    int montant = ui->lineEdit_montant_2->text().toInt();
    QString produit = ui->lineEdit_produit_2->text();
    QString datef = ui->lineEdit_montant_4->text() ;
    QString type ;
    if (ui->radioButton_4->isChecked())
    {
       type="client" ;
    }
    if (ui->radioButton_3->isChecked())
    {
       type="fournisseur" ;
    }

    facture E2(num_facture, montant, produit , type , datef);
    bool test = E2.modifier();
    if (test){
        ui->tableView->setModel(Et.afficher());
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                              QObject::tr("modification effectué"),
                              QMessageBox::Ok
                              );
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("modification non effectué"),
                              QMessageBox::Cancel
                              );
    }
}

void skanderwindow::on_bp_tricroi_clicked()
{
    ui->tableView->setModel(Et.Tricroi());
}

void skanderwindow::on_bp_tridecroi_clicked()
{
    ui->tableView->setModel(Et.Tridecroi());
}

void skanderwindow::on_pdf_clicked()
{
    int num_facture = ui->lineEdit_num_facture->text().toInt();
        int montant = ui->lineEdit_montant->text().toInt();
        QString produit = ui->lineEdit_produit->text();
        QString datef = ui->lineEdit_montant_3->text() ;
        QString type ;
        if (ui->radioButton->isChecked())
        {
           type="client" ;
        }
        if (ui->radioButton_2->isChecked())
        {
           type="fournisseur" ;
        }


        facture E(num_facture, montant, produit , type , datef);
        E.printPDF();
}


void skanderwindow::on_pushButton_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                          model->setQuery("select * from facture where montant < 100 ");
                          float montant1=model->rowCount();
                          model->setQuery("select * from facture where montant  between 100 and 200 ");
                          float montant2=model->rowCount();
                          model->setQuery("select * from facture where montant >200 ");
                          float montant3=model->rowCount();
                          float total=montant1+montant2+montant3;
                          QString a=QString("inferieur a 100  "+QString::number((montant1*100)/total,'f',2)+"%" );
                          QString b=QString("entre 100 et 200  "+QString::number((montant2*100)/total,'f',2)+"%" );
                          QString c=QString("+200  "+QString::number((montant3*100)/total,'f',2)+"%" );
                          QPieSeries *series = new QPieSeries();
                          series->append(a,montant1);
                          series->append(b,montant2);
                          series->append(c,montant3);
                  if (montant1!=0)
                  {QPieSlice *slice = series->slices().at(0);
                   slice->setLabelVisible();
                   slice->setPen(QPen());}
                  if ( montant2!=0)
                  {
                           // Add label, explode and define brush for 2nd slice
                           QPieSlice *slice1 = series->slices().at(1);
                           //slice1->setExploded();
                           slice1->setLabelVisible();
                  }
                  if(montant3!=0)
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
                          chart->setTitle("Pourcentage Par montant :Nombre de factures disponibles "+ QString::number(total));
                          chart->legend()->hide();
                          // Used to display the chart
                          QChartView *chartView = new QChartView(chart);
                          chartView->setRenderHint(QPainter::Antialiasing);
                          chartView->resize(1000,500);
                          chartView->show();
}

void skanderwindow::on_pb_excel_clicked()
{
    QTableView *table;
        table =  ui->tableView;
        QString filters("CSV files (.csv);;All files (.*)");
        QString defaultFilter("CSV files (*.csv)");
        QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                           filters, &defaultFilter);
        QFile file(fileName);
        QAbstractItemModel *model =  table->model();
        if (file.open(QFile::WriteOnly | QFile::Truncate)) {
            QTextStream data(&file);
            QStringList strList;
            for (int i = 0; i < model->columnCount(); i++) {
                if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                    strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                else
                    strList.append("");
            }
            data << strList.join(";") << "\n";
            for (int i = 0; i < model->rowCount(); i++) {
                strList.clear();
                for (int j = 0; j < model->columnCount(); j++) {
                    if (model->data(model->index(i, j)).toString().length() > 0)
                        strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                    else
                        strList.append("");
                }
                data << strList.join(";") + "\n";
            }
            file.close();
            //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");

    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                           tr("Excel Files (*.xls)"));
           if (fileName.isEmpty())
               return;

           ExportExcelObject obj(fileName, "mydata",ui->tableView);

           //colums to export
           obj.addField(0, "num_facture", "char(20)");
           obj.addField(1, "montant", "char(20)");
           obj.addField(2, "produit", "char(20)");
           obj.addField(2, "type", "char(20)");
           obj.addField(2, "datef", "char(20)");




           int retVal = obj.export2Excel();
           if( retVal > 0)
           {
               QMessageBox::information(this, tr("Done"),
                                        QString(tr("%1 records exported!")).arg(retVal)
                                        );
           }
}
}

/*void MainWindow::on_calcul_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                          model->setQuery("select  montant from facture  ");
                          float montant1=model->rowCount();
                          model->setQuery("select montant from facture  ");
                          float montant2=model->rowCount();
                          model->setQuery("select montant from facture  ");
                          float montant3=model->rowCount();
                          float total=montant1+montant2+montant3;
                          QString a=QString("le total des montant est"+int::number(total)"%" );

}
*/

void skanderwindow::on_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                           tr("Excel Files (*.xls)"));
           if (fileName.isEmpty())
               return;

           ExportExcelObject obj(fileName, "mydata", ui->tableView);

           //colums to export
           obj.addField(0, "NUM_FACTURE", "char(20)");
           obj.addField(1, "MONTANT", "char(20)");
           obj.addField(2, "PRODUIT", "char(20)");
           obj.addField(2, "TYPE", "char(20)");
           obj.addField(2, "DATEF", "char(20)");




           int retVal = obj.export2Excel();
           if( retVal > 0)
           {
               QMessageBox::information(this, tr("Done"),
                                        QString(tr("%1 records exported!")).arg(retVal)
                                        );
           }
}

void skanderwindow::on_afficher_clicked()
{
    ui->tab_produit->setModel(Pro.afficher());
    ui->tab_client->setModel(cli.afficher());
    ui->tab_fournisseur->setModel(four.afficher());
}

void skanderwindow::on_pushButton_4_clicked()
{

}

void skanderwindow::on_verifier_clicked()
{
    ui->tab_produit_3->setModel(Pro.afficher());
    ui->tab_client_3->setModel(cli.afficher());
    ui->tab_fournisseur_3->setModel(four.afficher());
}
