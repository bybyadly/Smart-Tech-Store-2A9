#ifndef MENU_H
#define MENU_H

#include <QMainWindow>


namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:


    void on_gestion_produits_clicked();

    void on_quitter_clicked();

    void on_gestion_clients_clicked();

    void on_gestion_fournisseurs_clicked();

    void on_gestion_employee_clicked();

    void on_gestion_factures_clicked();

    void on_cleardata_clicked();

private:
    Ui::Menu *ui;

};

#endif // MENU_H
