#ifndef MWINDOW_H
#define MWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QDialog>
#include <QFormLayout>
#include <QLayout>
#include <QSpinBox>
#include <QPushButton>
#include <QObject>
#include <QHBoxLayout>
#include <QString>
#include <QMessageBox>
#include "swindow.h"

class mwindow : public QWidget
{
    Q_OBJECT

private:

        QFormLayout** forms;
        QGroupBox**   groups;
        QCheckBox**   boxes3;
        QCheckBox*    commentaire;
        QLineEdit**   lines;
        QTextEdit*    role;
        QLineEdit*    date;
        QVBoxLayout** vlayouts;
        QHBoxLayout*  bottom;
        QPushButton*  quit;
        QPushButton*  generate;
 static QString       data;
        swindow*      dialog;
        QString*      elements;
 static bool          activators[4];


        enum parts {

                    NOM=0,
                    CLASSEMERE,
                    AUTEUR,
                    DATE,
                    ROLE,
                    INCLUSIONS,
                    TAILINCLUSION,
                    CONSTRUCTOR,
                    DESTRUCTOR,
                    COMMENTS

        };

        enum checkbool {

                    INCL=0,
                    CONST,
                    DESC,
                    COMM,


        };





public:
    explicit mwindow(QWidget *parent = 0);
    QPushButton* getQuit() { return quit; }
    virtual ~mwindow();

signals:

public slots:

void inclusions(int);
void constructor(int);
void destructor(int);

void comments(int);


void final();


};

#endif // MWINDOW_H
