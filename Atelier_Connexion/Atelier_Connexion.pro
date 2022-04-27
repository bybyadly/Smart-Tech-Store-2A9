#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql
QT+=sql
QT+=printsupport
QT+=charts
QT+=serialport
QT += multimedia
QT += multimediawidgets
QT +=widgets
QT += concurrent
QT+=serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    arduino.cpp \
    arduinoaziz.cpp \
    azizwindow.cpp \
    clients.cpp \
    elaawindow.cpp \
    employee.cpp \
    excel.cpp \
    facture.cpp \
    fournisseur.cpp \
    historique.cpp \
    historiqueclients.cpp \
    loginaziz.cpp \
    loginelaa.cpp \
    loginn.cpp \
    mahawindow.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    menu.cpp \
    produit.cpp \
    skanderwindow.cpp

HEADERS += \
    arduino.h \
    arduinoaziz.h \
    azizwindow.h \
    calculatrice.h \
    clients.h \
    elaawindow.h \
    employee.h \
    excel.h \
    facture.h \
    fournisseur.h \
    historique.h \
    historiqueclients.h \
    loginaziz.h \
    loginelaa.h \
    loginn.h \
    mahawindow.h \
        mainwindow.h \
    connection.h \
    menu.h \
    produit.h \
    qrcode.h \
    qrcode.h \
    skanderwindow.h

FORMS += \
        azizwindow.ui \
        elaawindow.ui \
        loginaziz.ui \
        loginelaa.ui \
        loginn.ui \
        mahawindow.ui \
        mainwindow.ui \
        menu.ui \
        skanderwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

