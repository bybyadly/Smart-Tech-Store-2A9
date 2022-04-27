#ifndef LOGINELAA_H
#define LOGINELAA_H

#include <QMainWindow>

namespace Ui {
class loginelaa;
}

class loginelaa : public QMainWindow
{
    Q_OBJECT

public:
    explicit loginelaa(QWidget *parent = nullptr);
    ~loginelaa();

private slots:
    void on_pb_login_clicked();

private:
    Ui::loginelaa *ui;
};

#endif // LOGINELAA_H
