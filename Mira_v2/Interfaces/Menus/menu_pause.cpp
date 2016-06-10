#include "menu_pause.h"

menu_pause::menu_pause(QWidget *parent,QMainWindow* fenetre):
    parent(parent),mainWindow(fenetre)
{
    QFont font("Bradley Hand ITC",16,75,false);
    font.setBold(true);

    QFont font1("Bradley Hand ITC",14,75,false);
    font1.setBold(true);

    btn_Reprendre = new QPushButton;
    btn_Reprendre->setMinimumSize(QSize(250, 55));
    btn_Reprendre->setMaximumSize(QSize(250, 55));
    btn_Reprendre->setFont(font);
    btn_Reprendre->setCursor(QCursor(Qt::PointingHandCursor));
    btn_Reprendre->setLayoutDirection(Qt::LeftToRight);
    btn_Reprendre->setStyleSheet("color: rgb(138, 0, 0);\n"
"border-color: rgb(138, 138,138);\n"
"background-color: rgb(241, 241, 241);");

    btn_nouvelle = new QPushButton;
    btn_nouvelle->setMinimumSize(QSize(190, 55));
    btn_nouvelle->setMaximumSize(QSize(190, 55));
    btn_nouvelle->setFont(font);
    btn_nouvelle->setCursor(QCursor(Qt::PointingHandCursor));
    btn_nouvelle->setFocusPolicy(Qt::StrongFocus);
    btn_Reprendre->setLayoutDirection(Qt::LeftToRight);
    btn_nouvelle->setStyleSheet(QString::fromUtf8("color: rgb(138, 0, 0);\n"
"border-color: rgb(138, 138,138);\n"
"background-color: rgb(241, 241, 241);"));

    btn_Accueil = new QPushButton;
    btn_Accueil->setMinimumSize(QSize(230, 55));
    btn_Accueil->setMaximumSize(QSize(230, 55));
    btn_Accueil->setFont(font1);
    btn_Accueil->setCursor(QCursor(Qt::PointingHandCursor));
    btn_Accueil->setFocusPolicy(Qt::StrongFocus);
    btn_Reprendre->setLayoutDirection(Qt::LeftToRight);
    btn_Accueil->setStyleSheet(QString::fromUtf8("color: rgb(138, 0, 0);\n"
"border-color: rgb(138, 138,138);\n"
"background-color: rgb(241, 241, 241);"));

    btn_Exit = new QPushButton;
    btn_Exit->setMinimumSize(QSize(150, 40));
    btn_Exit->setMaximumSize(QSize(150, 40));
    btn_Exit->setFont(font);
    btn_Exit->setCursor(QCursor(Qt::PointingHandCursor));
    btn_Exit->setFocusPolicy(Qt::StrongFocus);
    btn_Reprendre->setLayoutDirection(Qt::LeftToRight);
    btn_Exit->setStyleSheet(QString::fromUtf8("color: rgb(138, 0, 0);\n"
"border-color: rgb(138, 138,138);\n"
"background-color: rgb(241, 241, 241);"));


    btn_Reprendre->setText("&Reprendre la \nPartie");
    btn_nouvelle->setText("Nouvelle Partie");
    btn_Accueil->setText("Vers le menu\nd'accueil");
    btn_Exit->setText("&Quitter");

}

void menu_pause::afficher_menu_pause(QGridLayout* layout)
{
    this->layout = new QVBoxLayout;
    this->layout->addWidget(btn_Reprendre,1,Qt::AlignCenter);
    this->layout->addWidget(btn_nouvelle,1,Qt::AlignCenter);
    this->layout->addWidget(btn_Accueil,2,Qt::AlignCenter);
    this->layout->addWidget(btn_Exit,2,Qt::AlignCenter);
    layout->addLayout(this->layout,1,2,Qt::AlignHCenter | Qt::AlignVCenter);

    parent->setLayout(layout);

    QWidget::connect(btn_Exit,SIGNAL(clicked()),mainWindow,SLOT(close()));
    QWidget::connect(btn_nouvelle,SIGNAL(clicked()),mainWindow,SLOT(afficher_panel_creationJrs()));
    QWidget::connect(btn_Accueil,SIGNAL(clicked()),mainWindow,SLOT(afficher_menu_accueil()));
}

menu_pause::~menu_pause()
{
    delete layout;
    delete btn_Reprendre;
    delete btn_nouvelle;
    delete btn_Accueil;
    delete btn_Exit;
}


