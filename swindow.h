#ifndef SWINDOW_H
#define SWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>


class swindow : public QDialog
{
    Q_OBJECT

private:


    QTextEdit*   text;
    QPushButton* close;
    QVBoxLayout* order;




public:
    explicit swindow(QDialog *parent = 0);
    QTextEdit* gettoText() { return text; }
    virtual ~swindow();

signals:

public slots:
};

#endif // SWINDOW_H
