/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *gb1;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *le_nom;
    QLineEdit *la_image;
    QLineEdit *le_prix;
    QLineEdit *la_description;
    QPushButton *pb_ajouter;
    QLineEdit *le_id;
    QGroupBox *groupBox_3;
    QLabel *label_11;
    QLineEdit *le_id_sup;
    QPushButton *pb_supprimer;
    QPushButton *pb_exit;
    QGroupBox *gb1_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *newname;
    QLineEdit *newimage;
    QLineEdit *newprix;
    QLineEdit *newdesc;
    QPushButton *pb_modifier;
    QLineEdit *new_id;
    QGroupBox *groupBox;
    QTableView *tab_produits;
    QPushButton *pb_afficher;
    QPushButton *pb_tricroi;
    QPushButton *pb_tridecroi;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1249, 740);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 1231, 661));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gb1 = new QGroupBox(tab);
        gb1->setObjectName(QStringLiteral("gb1"));
        gb1->setGeometry(QRect(0, 0, 321, 471));
        label = new QLabel(gb1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 56, 16));
        label_2 = new QLabel(gb1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 56, 16));
        label_3 = new QLabel(gb1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 110, 56, 16));
        label_4 = new QLabel(gb1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 280, 56, 16));
        label_5 = new QLabel(gb1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 320, 101, 16));
        le_nom = new QLineEdit(gb1);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(80, 70, 161, 22));
        la_image = new QLineEdit(gb1);
        la_image->setObjectName(QStringLiteral("la_image"));
        la_image->setGeometry(QRect(80, 110, 171, 141));
        le_prix = new QLineEdit(gb1);
        le_prix->setObjectName(QStringLiteral("le_prix"));
        le_prix->setGeometry(QRect(80, 280, 113, 22));
        la_description = new QLineEdit(gb1);
        la_description->setObjectName(QStringLiteral("la_description"));
        la_description->setGeometry(QRect(10, 340, 301, 71));
        pb_ajouter = new QPushButton(gb1);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(220, 430, 93, 28));
        le_id = new QLineEdit(gb1);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(80, 30, 113, 22));
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 480, 371, 121));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 60, 71, 16));
        le_id_sup = new QLineEdit(groupBox_3);
        le_id_sup->setObjectName(QStringLiteral("le_id_sup"));
        le_id_sup->setGeometry(QRect(100, 50, 211, 31));
        pb_supprimer = new QPushButton(groupBox_3);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(270, 90, 93, 28));
        pb_exit = new QPushButton(tab);
        pb_exit->setObjectName(QStringLiteral("pb_exit"));
        pb_exit->setGeometry(QRect(1120, 590, 93, 28));
        gb1_2 = new QGroupBox(tab);
        gb1_2->setObjectName(QStringLiteral("gb1_2"));
        gb1_2->setGeometry(QRect(330, 0, 321, 471));
        label_6 = new QLabel(gb1_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 30, 56, 16));
        label_7 = new QLabel(gb1_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 70, 56, 16));
        label_8 = new QLabel(gb1_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 110, 56, 16));
        label_9 = new QLabel(gb1_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 280, 56, 16));
        label_10 = new QLabel(gb1_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 320, 101, 16));
        newname = new QLineEdit(gb1_2);
        newname->setObjectName(QStringLiteral("newname"));
        newname->setGeometry(QRect(80, 70, 161, 22));
        newimage = new QLineEdit(gb1_2);
        newimage->setObjectName(QStringLiteral("newimage"));
        newimage->setGeometry(QRect(80, 110, 171, 141));
        newprix = new QLineEdit(gb1_2);
        newprix->setObjectName(QStringLiteral("newprix"));
        newprix->setGeometry(QRect(80, 280, 113, 22));
        newdesc = new QLineEdit(gb1_2);
        newdesc->setObjectName(QStringLiteral("newdesc"));
        newdesc->setGeometry(QRect(10, 340, 301, 71));
        pb_modifier = new QPushButton(gb1_2);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(220, 430, 93, 28));
        new_id = new QLineEdit(gb1_2);
        new_id->setObjectName(QStringLiteral("new_id"));
        new_id->setGeometry(QRect(80, 30, 113, 22));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(660, 0, 571, 471));
        tab_produits = new QTableView(groupBox);
        tab_produits->setObjectName(QStringLiteral("tab_produits"));
        tab_produits->setGeometry(QRect(10, 30, 551, 391));
        pb_afficher = new QPushButton(groupBox);
        pb_afficher->setObjectName(QStringLiteral("pb_afficher"));
        pb_afficher->setGeometry(QRect(470, 440, 93, 28));
        pb_tricroi = new QPushButton(groupBox);
        pb_tricroi->setObjectName(QStringLiteral("pb_tricroi"));
        pb_tricroi->setGeometry(QRect(370, 440, 93, 28));
        pb_tridecroi = new QPushButton(groupBox);
        pb_tridecroi->setObjectName(QStringLiteral("pb_tridecroi"));
        pb_tridecroi->setGeometry(QRect(260, 440, 101, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1249, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        gb1->setTitle(QApplication::translate("MainWindow", "Ajouter un Produit", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Image", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Supprimer un Produit", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Saisir l'ID", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        pb_exit->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        gb1_2->setTitle(QApplication::translate("MainWindow", "Modifier un Produit", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Image", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Prix", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Description", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Afficher un Produit", Q_NULLPTR));
        pb_afficher->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        pb_tricroi->setText(QApplication::translate("MainWindow", "Tri Croissant", Q_NULLPTR));
        pb_tridecroi->setText(QApplication::translate("MainWindow", "Tri D\303\251croissant", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "CRUD", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
