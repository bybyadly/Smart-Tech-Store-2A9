#include "connection.h"

//test Tutoriel Git

Connection::Connection(){}

bool Connection::createconnect()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Project");
db.setUserName("abrougui");//inserer nom de l'utilisateur
db.setPassword("esprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}

void Connection::closeConnection(){db.close();}
