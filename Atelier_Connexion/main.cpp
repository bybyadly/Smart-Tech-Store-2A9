#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QTranslator>
#include <QInputDialog>
#include "menu.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu m;
    Connection c;
    bool test=c.createconnect();
    if(test)

    { QTranslator t;
        QTranslator guiTranslator;
       QStringList languages;
       languages <<"Frensh"<<"English";
       QString lang = QInputDialog::getItem(NULL,"select Language",
                                            "Language",languages);
       if(lang=="Englais")
       {
           t.load("C:/Users/Hp/Desktop/gittt/Smart-Tech-Store-2A9/Atelier_Connexion/Englais.qm");
           a.installTranslator(&t);
       }

        m.show();
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
