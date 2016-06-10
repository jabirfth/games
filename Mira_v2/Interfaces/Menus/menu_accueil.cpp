#include "menu_accueil.h"

menu_accueil::menu_accueil(QWidget *parent,QMainWindow* fenetre):
    parent(parent),mainWindow(fenetre)
{
    QFont font("Bradley Hand ITC",16,75,false);
    font.setBold(true);

    QFont font1("Bradley Hand ITC",14,75,false);
    font1.setBold(true);

    btn_JrVsJr = new QPushButton;
    btn_JrVsJr->setMinimumSize(QSize(250, 55));
    btn_JrVsJr->setMaximumSize(QSize(250, 55));
    btn_JrVsJr->setFont(font);
    btn_JrVsJr->setCursor(QCursor(Qt::PointingHandCursor));
    btn_JrVsJr->setLayoutDirection(Qt::LeftToRight);
    btn_JrVsJr->setStyleSheet("color: rgb(138, 0, 0);\n"
"border-color: rgb(138, 138,138);\n"
"background-color: rgb(241, 241, 241);");

    btn_JrVsOrdi = new QPushButton;
    btn_JrVsOrdi->setMinimumSize(QSize(190, 55));
    btn_JrVsOrdi->setMaximumSize(QSize(190, 55));
    btn_JrVsOrdi->setFont(font);
    btn_JrVsOrdi->setCursor(QCursor(Qt::PointingHandCursor));
    btn_JrVsOrdi->setFocusPolicy(Qt::StrongFocus);
    btn_JrVsJr->setLayoutDirection(Qt::LeftToRight);
    btn_JrVsOrdi->setStyleSheet(QString::fromUtf8("color: rgb(138, 0, 0);\n"
"border-color: rgb(138, 138,138);\n"
"background-color: rgb(241, 241, 241);"));

    btn_LoadGame = new QPushButton;
    btn_LoadGame->setMinimumSize(QSize(230, 55));
    btn_LoadGame->setMaximumSize(QSize(230, 55));
    btn_LoadGame->setFont(font1);
    btn_LoadGame->setCursor(QCursor(Qt::PointingHandCursor));
    btn_LoadGame->setFocusPolicy(Qt::StrongFocus);
    btn_JrVsJr->setLayoutDirection(Qt::LeftToRight);
    btn_LoadGame->setStyleSheet(QString::fromUtf8("color: rgb(138, 0, 0);\n"
"border-color: rgb(138, 138,138);\n"
"background-color: rgb(241, 241, 241);"));

    btn_Rules = new QPushButton;
    btn_Rules->setMinimumSize(QSize(230, 50));
    btn_Rules->setMaximumSize(QSize(230, 50));
    btn_Rules->setFont(font);
    btn_Rules->setCursor(QCursor(Qt::PointingHandCursor));
    btn_Rules->setFocusPolicy(Qt::StrongFocus);
    btn_JrVsJr->setLayoutDirection(Qt::LeftToRight);
    btn_Rules->setStyleSheet(QString::fromUtf8("color: rgb(138, 0, 0);\n"
"border-color: rgb(138, 138,138);\n"
"background-color: rgb(241, 241, 241);"));

    btn_Exit = new QPushButton;
    btn_Exit->setMinimumSize(QSize(150, 40));
    btn_Exit->setMaximumSize(QSize(150, 40));
    btn_Exit->setFont(font);
    btn_Exit->setCursor(QCursor(Qt::PointingHandCursor));
    btn_Exit->setFocusPolicy(Qt::StrongFocus);
    btn_JrVsJr->setLayoutDirection(Qt::LeftToRight);
    btn_Exit->setStyleSheet(QString::fromUtf8("color: rgb(138, 0, 0);\n"
"border-color: rgb(138, 138,138);\n"
"background-color: rgb(241, 241, 241);"));


    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/icones/multiplayer"), QSize(), QIcon::Normal, QIcon::Off);
    btn_JrVsJr->setIcon(icon);
    btn_JrVsJr->setIconSize(QSize(64, 64));

    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/images/icones/machine"), QSize(), QIcon::Normal, QIcon::Off);
    btn_JrVsOrdi->setIcon(icon1);
    btn_JrVsOrdi->setIconSize(QSize(45, 45));

    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/images/icones/load"), QSize(), QIcon::Normal, QIcon::Off);
    btn_LoadGame->setIcon(icon2);
    btn_LoadGame->setIconSize(QSize(45, 45));

    QIcon icon3;
    icon3.addFile(QString::fromUtf8(":/images/icones/regles"), QSize(), QIcon::Normal, QIcon::Off);
    btn_Rules->setIcon(icon3);
    btn_Rules->setIconSize(QSize(64, 64));

    QIcon icon4;
    icon4.addFile(QString::fromUtf8(":/images/icones/quitter"), QSize(), QIcon::Normal, QIcon::Off);
    btn_Exit->setIcon(icon4);
    btn_Exit->setIconSize(QSize(32, 32));

    btn_JrVsJr->setText("&Nouvelle Partie\nMultijoueur");
    btn_JrVsOrdi->setText("Jouer contre\nl'&Ordinateur");
    btn_LoadGame->setText("&Charger une Partie\nsauvegardee");
    btn_Rules->setText("&Regle du Jeu");
    btn_Exit->setText("&Quitter");

}

void menu_accueil::afficher_menu_accueil(QGridLayout* layout)
{
    layout->addWidget(btn_JrVsJr,1,1,Qt::AlignCenter);
    //layout->addWidget(btn_JrVsOrdi,2,1,Qt::AlignCenter);
    //layout->addWidget(btn_LoadGame,3,1,Qt::AlignCenter);
    layout->addWidget(btn_Rules,4,1,Qt::AlignCenter);
    layout->addWidget(btn_Exit,5,1,Qt::AlignCenter);

    parent->setLayout(layout);

    QWidget::connect(btn_Exit,SIGNAL(clicked()),mainWindow,SLOT(close()));
    QWidget::connect(btn_JrVsJr,SIGNAL(clicked()),mainWindow,SLOT(afficher_panel_creationJrs()));
}

menu_accueil::~menu_accueil()
{
    delete btn_JrVsJr;
    delete btn_JrVsOrdi;
    delete btn_LoadGame;
    delete btn_Rules;
    delete btn_Exit;
}


