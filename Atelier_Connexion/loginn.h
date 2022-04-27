#ifndef LOGINN_H
#define LOGINN_H

#include <QMainWindow>



namespace Ui {
class loginn;
}

class loginn : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginn(QWidget *parent = nullptr);
    ~loginn();


private slots:

void on_pb_login_clicked();
private:
Ui::loginn *ui;
};

#endif // LOGINN_H
