#include <QtGui/QApplication>
#include "typing_characteristics.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    typing_characteristics foo;
    foo.show();
    return app.exec();
}
