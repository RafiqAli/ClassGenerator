#include "swindow.h"

swindow::swindow(QDialog *parent) : QDialog(parent)
{

    text  = new QTextEdit;
    close = new QPushButton("Fermer");
    order = new QVBoxLayout(this);

    order->addWidget(text);
    order->addWidget(close);

    resize(250,400);

    QObject::connect(close,SIGNAL(clicked(bool)),this,SLOT(accept()));


}



swindow::~swindow() {

    delete text;
    delete close;
    delete order;
}
