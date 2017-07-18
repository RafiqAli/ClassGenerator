#include <QApplication>
#include <QWidget>
#include "mwindow.h"

int main(int argc, char* argv[]) {

    QApplication app(argc,argv);

    mwindow mywindow;



    mywindow.show();


    return app.exec();
}
