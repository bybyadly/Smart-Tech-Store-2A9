#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class qcamera;
class qcameraviewfinder;
class qcameraimagecapture;
class qvboxlayout;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    qcamera *mcamera;
    qcameraviewfinder *mcameraviewfinder;
    qcameraimagecapture *mcameraimagecapture;
    qvboxlayout *mlayout;

};
#endif // WIDGET_H
