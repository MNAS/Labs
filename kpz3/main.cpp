#include <QApplication>
#include <QSqlDatabase>
#include <QTextStream>
#include <QSqlQuery>

#include <QtWidgets>
#include <QtSql>

#include "ship_main.h"

int main ( int argc, char *argv[] ) {
    QApplication app ( argc, argv );

    ship_main *foo= new ship_main ;
    foo->show();
    return app.exec();
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
