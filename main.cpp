#include "mainwindow.h"
#include "QApplication"
#include "connection.h"
#include <QMessageBox>

#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;

    bool test = c.createconnect();

    QTranslator t;
            QTranslator guiTranslator;
           QStringList languages;
           languages <<"Frensh"<<"Englais";
           QString lang = QInputDialog::getItem(NULL,"select Language",
                                                "Language",languages);
           if(lang=="Englais")
           {
               t.load(":/Englais.qm");
               a.installTranslator(&t);
           }

    MainWindow w;
    if (test){
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                              QObject::tr("Connection successful"),
                              QMessageBox::Ok
                              );


    }else {
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Connection failed"),
                              QMessageBox::Cancel
                              );
    }
    return a.exec();

}
