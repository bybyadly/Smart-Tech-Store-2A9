#include "widget.h"
#include "ui_widget.h"
#include<QCamera>
#include<QCameraViewfinder>
#include<QCameraImageCapture>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mcamera = newQCamera(this);
}

Widget::~Widget()
{
    delete ui;
}

