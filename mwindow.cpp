#include "mwindow.h"

QString mwindow::data = "";

bool mwindow::activators[] = {false};

mwindow::mwindow(QWidget *parent) : QWidget(parent)
{


    dialog      = new swindow;

    elements    = new QString[10];

    forms       = new QFormLayout*[2];
    groups      = new QGroupBox*[3];
    boxes3      = new QCheckBox*[3];
    lines       = new QLineEdit*[3];
    vlayouts    = new QVBoxLayout*[3];

    commentaire = new QCheckBox("Ajouter un commentaire ");
    date        = new QLineEdit;
    role        = new QTextEdit;


    for(int i=0;i<2;i++) forms[i]    = new QFormLayout;
    for(int i=0;i<3;i++) groups[i]   = new QGroupBox;
    for(int i=0;i<3;i++) lines[i]    = new QLineEdit;

    bottom = new QHBoxLayout;

    generate = new QPushButton("Générer le code ");
    quit     = new QPushButton("Quitter");

    vlayouts[0] = new QVBoxLayout;
    vlayouts[1] = new QVBoxLayout(this);


    boxes3[0] = new QCheckBox("protéger le header contre les inclusions multiples");
    boxes3[1] = new QCheckBox("Générer un constructeur par défault.");
    boxes3[2] = new QCheckBox("Générer un destructeur");

    for(int i=0;i<3;i++) vlayouts[0]->addWidget(boxes3[i]);

    groups[0]->setTitle("Définition du classe");

    forms[0]->addRow("Nom : ",lines[0]);
    forms[0]->addRow("Classe Mére : ",lines[1]);

    groups[0]->setLayout(forms[0]);

    groups[1]->setTitle("Options");
    groups[1]->setLayout(vlayouts[0]);


    forms[1]->addRow("Auteur : ",lines[2]);
    forms[1]->addRow("Date de création : ",date);
    forms[1]->addRow("Role de la classe : ",role);

    groups[2]->setTitle("Commentaires");

    groups[2]->setLayout(forms[1]);


    for(int i=0;i<2;i++) vlayouts[1]->addWidget(groups[i]);

    vlayouts[1]->addWidget(commentaire);
    vlayouts[1]->addWidget(groups[2]);

    bottom->addWidget(generate);
    bottom->addWidget(quit);

    vlayouts[1]->addLayout(bottom);

    groups[2]->setDisabled(true);

    dialog->gettoText()->setReadOnly(true);
    dialog->


    QObject::connect(boxes3[INCL],SIGNAL(stateChanged(int)),this,SLOT(inclusions(int)));
    QObject::connect(boxes3[CONST],SIGNAL(stateChanged(int)),this,SLOT(constructor(int)));
    QObject::connect(boxes3[DESC],SIGNAL(stateChanged(int)),this,SLOT(destructor(int)));
    QObject::connect(commentaire,SIGNAL(stateChanged(int)),this,SLOT(comments(int)));
    QObject::connect(quit,SIGNAL(clicked(bool)),this,SLOT(close()));
    QObject::connect(commentaire,SIGNAL(clicked(bool)),groups[2],SLOT(setEnabled(bool)));




    QObject::connect(generate,SIGNAL(clicked(bool)),this,SLOT(final()));



}



void mwindow::comments(int status) {

    if(status == Qt::Checked) activators[COMM] = true;

    else if(status == Qt::Unchecked) activators[COMM] = false;
}


void mwindow::inclusions(int status) {

    if(status == Qt::Checked) {

             activators[INCL] = true;

       } else if (status == Qt::Unchecked) activators[INCL]  = false;
}

void mwindow::constructor(int status) {

       if(status == Qt::Checked) {

            activators[CONST] = true;

      } else if (status == Qt::Unchecked) activators[CONST] = false;
}


void mwindow::destructor(int status) {

   if(status == Qt::Checked) {

         activators[DESC] = true;

    } else if (status == Qt::Unchecked) activators[DESC]  = false;

}




void mwindow::final() {


    if(!(lines[0]->text().isEmpty() && lines[1]->text().isEmpty())) {

    for(int i=0;i<10;i++) elements[i] = "";

    data = "";

    elements[NOM]        = lines[0]->text().toLower();
    elements[CLASSEMERE] = lines[1]->text().toLower();


    if(activators[COMM]) {

        elements[AUTEUR]     = lines[2]->text();
        elements[DATE]       = date->text();
        elements[ROLE]       = role->toPlainText();

        elements[COMMENTS] = "/* \n\tAUTEUR : " + elements[AUTEUR] + " \n\tDATE     : " + elements[DATE] + " \n\tROLE     : " + elements[ROLE] + "\n\n*/ \n\n";

        data += elements[COMMENTS];

    }

    if(activators[INCL]) {

        elements[INCLUSIONS] = "#ifndef " + elements[NOM].toUpper() + "_H \n\n#define " + elements[NOM].toUpper() + "_H \n";

        elements[TAILINCLUSION] = "#endif // " + elements[NOM].toUpper();
    }

    if(activators[CONST]) {

        elements[CONSTRUCTOR] = elements[NOM] + "(); \n";
    }

    if(activators[DESC]) {

        elements[DESTRUCTOR] = "~" + elements[NOM] + "(); \n";
    }

    data += elements[INCLUSIONS] + "\n \n class " + elements[NOM] + " : public " + elements[CLASSEMERE] + " { \n \n public: \n \t" + elements[CONSTRUCTOR] + "\n \t" + elements[DESTRUCTOR] + "\n \n private: \n \n }; \n \n" + elements[TAILINCLUSION];

    dialog->gettoText()->setText(data);

    dialog->exec();

    } else  QMessageBox::warning(this,"Avertissement","Veuillez remplir les cases nom classe et classe mére .", QMessageBox::Ok , QMessageBox::NoButton );



}



mwindow::~mwindow() {

    delete [] forms;
    delete [] groups;
    delete [] boxes3;
    delete [] lines;
    delete [] vlayouts;
    delete [] elements;

    delete forms;
    delete groups;
    delete boxes3;
    delete lines;
    delete vlayouts;

    delete commentaire;
    delete role;
    delete date;
    delete bottom;
    delete quit;
    delete generate;

}







