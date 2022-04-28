#include "mahawindow.h"
#include "ui_mahawindow.h"
#include "historique.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
//#include<QDate>
#include<QTableWidget>
#include<QPixmap>
#include<QTextDocument>
 #include<QDesktopServices>

#include "employee.h"
#include "QFile"
#include "QTextStream"

#include <QPieSlice>
#include <QPieSeries>

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
#include "arduinomaha.h"


mahawindow::mahawindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mahawindow)
{
    ui->setupUi(this);


   ui->l_CIN->setValidator(new QIntValidator(0,999999,this));
   ui->l_tel->setValidator(new QIntValidator(0,999999999,this));
   ui->l_salaire->setValidator(new QIntValidator(0,999999999,this));

    ui->tab_etud->setModel(E.afficher());
    ui->tableViewHistorique->setModel(HI.Afficher());

    int ret=M1.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< M1.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<M1.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(M1.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).
}

mahawindow::~mahawindow()
{
    delete ui;

}


void mahawindow::on_ajouter_clicked()
{
 ui->tab_etud->setModel(E.afficher());

    int CIN=ui->l_CIN->text().toInt();
    int salaire=ui->l_salaire->text().toInt();
    int tel=ui->l_tel->text().toInt();

    QString nom=ui->l_nom->text();
    QString prenom=ui->l_prenom->text();

    QString sexe(ui->l_sexe->currentText());
    QString fonction(ui->comboBox->currentText());

     employee E(nom,prenom,CIN,fonction,salaire,tel,sexe);

bool test=E.ajouter();

if(test)

    ui->tab_etud->setModel(E.afficher()); //refresh
        QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("Ajout avec succes\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_etud->setModel(E.afficher()); //refresh

}




void mahawindow::on_button_modifier_clicked()
{ui->tab_etud->setModel(E.afficher());

    bool    test=E.modifierj(ui->l_CIN->text().toInt(),ui->l_nom->text(),ui->l_prenom->text(),ui->comboBox->currentText(),ui->l_salaire->text().toInt(),ui->l_sexe->currentText(),ui->l_tel->text().toInt());

    if (test)
          {
                  ui->tab_etud->setModel(E.afficher()); //refresh

              QMessageBox::information(nullptr,QObject::tr("OK"),
                                   QObject::tr("modification établie"),
                                   QMessageBox::Ok);}
          else{
          QMessageBox::critical(nullptr,QObject::tr("ERROR404"),
                                  QObject::tr("modification non établie"),
                                  QMessageBox::Cancel);}
}

void mahawindow::on_supprimer_clicked()
{

    employee E1; E1.setcin(ui->lineEdit_sup->text().toInt());
    bool test=E1.supprimer(E1.getcin());
    QMessageBox msgBox;
    if(test)
    {
         ui->tab_etud->setModel(E1.afficher());
        msgBox.setText("suppression avec succes.");
    }
    else
          msgBox.setText("echec d'ajout");
                msgBox.exec();


}

void mahawindow::on_radioButton_clicked() //tri par fonction
{
    QMessageBox msgBox ;
        QSqlQueryModel * model= new QSqlQueryModel();



           model->setQuery("select * from table1 order by fonction");

           model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
                    ui->tab_etud_4->setModel(model);
                    ui->tab_etud_4->show();
                    msgBox.setText("Tri avec succés.");
                    msgBox.exec();
}

void mahawindow::on_radioButton_3_clicked() //tri par cin
{
    QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();


               model->setQuery("select * from table1 order by CIN ");
               model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
               model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
       model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
                        ui->tab_etud_4->setModel(model);
                        ui->tab_etud_4->show();
                        msgBox.setText("Tri avec succés.");
                        msgBox.exec();
}

void mahawindow::on_radioButton_2_clicked() //tri par nom
{
    QMessageBox msgBox ;
        QSqlQueryModel * model= new QSqlQueryModel();



           model->setQuery("select * from table1 order by nom");

           model->setHeaderData(0, Qt::Horizontal, QObject::tr("cin"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("fonction"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("salaire"));
           model->setHeaderData(5, Qt::Horizontal, QObject::tr("sexe"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
                    ui->tab_etud_4->setModel(model);
                    ui->tab_etud_4->show();
                    msgBox.setText("Tri avec succés.");
                    msgBox.exec();
}

void mahawindow::on_l_r_textChanged(const QString &arg1)
{
    employee a;
        if(ui->l_r->text() == "")
            {
                ui->rech->setModel(a.afficher());
            }
            else
            {
                 ui->rech->setModel(a.rechercher(ui->l_r->text()));
            }
}


void mahawindow::on_pushButton_clicked() //PDF
{
   employee emp;
    emp.genererPDF();
    QString link="C:/Users/Administrateur/OneDrive/Bureau/liste.pdf";
        QDesktopServices::openUrl(QUrl(link));
}

void mahawindow::on_historique_clicked()
{

}




void mahawindow::on_pushButton_2_clicked()
{
    QString strStream;

                            QTextStream out(&strStream);

                            const int rowCount = ui->tab_etud->model()->rowCount();
                            const int columnCount = ui->tab_etud->model()->columnCount();
                            QString TT = QDateTime::currentDateTime().toString();
                            out <<"<html>\n"
                                  "<head>\n"
                                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                << "<title>ERP - COMmANDE LIST<title>\n "
                                << "</head>\n"
                                "<body bgcolor=#ffffff link=#5000A0>\n"
                                   "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                                   +"<img src=file:C:\\Users\\Aziz Abrougui\\Documents\\generated_pdf_client.pdf />"
                                   "<h1 style=\"text-align: center;\"><strong> ***LISTE DES  licence commerciale *** </strong></h1>"


                                "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                                  "</br> </br>";
                            // headers
                            out << "<thead><tr bgcolor=#d6e5ff>";
                            for (int column = 0; column < columnCount; column++)
                                if (!ui->tab_etud->isColumnHidden(column))
                                    out << QString("<th>%1</th>").arg(ui->tab_etud->model()->headerData(column, Qt::Horizontal).toString());
                            out << "</tr></thead>\n";

                            // data table
                            for (int row = 0; row < rowCount; row++) {
                                out << "<tr>";
                                for (int column = 0; column < columnCount; column++) {
                                    if (!ui->tab_etud->isColumnHidden(column)) {
                                        QString data =ui->tab_etud->model()->data(ui->tab_etud->model()->index(row, column)).toString().simplified();
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



void mahawindow::on_stat_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
                QSqlQueryModel * model= new QSqlQueryModel();
                model->setQuery("select * from table1 where CIN < 19999 ");
                float taille=model->rowCount();
                model->setQuery("select * from table1 where CIN  between 1100 and 29999 ");
                float taillee=model->rowCount();
                model->setQuery("select * from table1 where CIN >29999 ");
                float tailleee=model->rowCount();
                float total=taille+taillee+tailleee;
                QString a=QString("bien . "+QString::number((taille*100)/total,'f',2)+"%" );
                QString b=QString("moyenne .  "+QString::number((taillee*100)/total,'f',2)+"%" );
                QString c=QString("mauvais ."+QString::number((tailleee*100)/total,'f',2)+"%" );
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
                chart->setTitle("distribution employee :Nombre Des employee "+ QString::number(total));
                chart->legend()->hide();
                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();
}

void mahawindow::on_pushButton_historrr_clicked()
{

    int id = ui->lineEditIDHIS->text().toInt();
    QString operation = ui->lineEdit_operation_hist->text();
    Historique H(operation, id);
    H.Ajouter();
    ui->tableViewHistorique->setModel(HI.Afficher());


}

void mahawindow::on_pushButton_3_clicked()
{
    ui->tab_etud->setModel(E.afficher());
    ui->tableViewHistorique->setModel(HI.Afficher());
}



void mahawindow::on_open_clicked()
{
   M1.write_to_arduino("2");
}

void mahawindow::on_close_clicked()
{
    M1.write_to_arduino("1");
}

void mahawindow::update_label()
{
    data=M1.read_from_arduino();


    if(data=="2")

        ui->label_fournisseur->setText("Operation succeed WELCOME"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="1")

        ui->label_fournisseur->setText("See you soon");
}