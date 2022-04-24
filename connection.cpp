#include "connection.h"

Connection::Connection(){}

bool Connection::createconnect()
{
db = QSqlDatabase::addDatabase("QODBC");
bool test=false;
db.setDatabaseName("Project_Qt");
db.setUserName("maatoug");//inserer nom de l'utilisateur
db.setPassword("eprit18");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}

void Connection::closeConnection(){db.close();}

