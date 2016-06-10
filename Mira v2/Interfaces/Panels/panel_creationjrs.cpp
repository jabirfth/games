#include "panel_creationjrs.h"
#include "ui_panel_creationjrs.h"

#include "../fenetre_principale.h"

panel_creationJrs::panel_creationJrs(QWidget *parent, QMainWindow *fenetre) :
    parent(parent),mainWindow(fenetre)
{
    QFont font;
    font.setFamily(QString::fromUtf8("Segoe Print"));
    font.setPointSize(16);

    panel = new QFrame;
    panel->setMinimumSize(700,300);
    panel->setMaximumSize(700,300);
    panel->setStyleSheet("background-color: rgb(241, 241, 241);");

    lbl_pseudo = new QLabel(panel);
    lbl_pseudo->setMinimumSize(QSize(275, 36));
    lbl_pseudo->setFont(font);
    lbl_pseudo->setStyleSheet("color: rgb(0, 0, 0);");

    txt_Pseudo = new QLineEdit(panel);
    txt_Pseudo->setMinimumSize(QSize(171, 31));
    txt_Pseudo->setMaximumSize(QSize(171, 31));
    txt_Pseudo->setFont(font);
    txt_Pseudo->setStyleSheet("background-color: rgb(255, 255, 255);");

    lbl_clrpion = new QLabel(panel);
    lbl_clrpion->setMinimumSize(QSize(348, 36));
    lbl_clrpion->setFont(font);
    lbl_clrpion->setStyleSheet("color: rgb(0, 0, 0);");

    cbx_ClrPion = new QComboBox(panel);
    cbx_ClrPion->setMinimumSize(QSize(140, 30));
    cbx_ClrPion->setMaximumSize(QSize(140, 30));
    cbx_ClrPion->setFont(font);
    cbx_ClrPion->setStyleSheet("background-color: rgb(255, 255, 255);");
    cbx_ClrPion->clear();
    cbx_ClrPion->addItem("");
    QIcon icon;
    icon.addFile(":/images/pions/1", QSize(32,32), QIcon::Normal, QIcon::Off);
    cbx_ClrPion->addItem(icon, "Vert");
    QIcon icon1;
    icon1.addFile(":/images/pions/2", QSize(32,32), QIcon::Normal, QIcon::Off);
    cbx_ClrPion->addItem(icon1,"Jaune");
    QIcon icon2;
    icon2.addFile(":/images/pions/3", QSize(32,32), QIcon::Normal, QIcon::Off);
    cbx_ClrPion->addItem(icon2,"Bleu");
    QIcon icon3;
    icon3.addFile(":/images/pions/4", QSize(32,32), QIcon::Normal, QIcon::Off);
    cbx_ClrPion->addItem(icon3, "Marron");

    btn_CreerJr = new QPushButton(panel);
    btn_CreerJr->setMinimumSize(QSize(100, 44));
    btn_CreerJr->setMaximumSize(QSize(100, 44));
    btn_CreerJr->setCursor(QCursor(Qt::PointingHandCursor));
    btn_CreerJr->setFont(font);
    btn_CreerJr->setStyleSheet("color: rgb(0, 0, 0);\n");

    btn_Commencer = new QPushButton(panel);
    btn_Commencer->setMinimumSize(QSize(160, 44));
    btn_Commencer->setMaximumSize(QSize(160, 44));
    btn_Commencer->setCursor(QCursor(Qt::PointingHandCursor));
    btn_Commencer->setFont(font);
    btn_Commencer->setStyleSheet("color: rgb(0, 0, 0);");
    btn_Commencer->setVisible(false);

    lbl_pseudo->setText("Saisir votre Pseudoname :");
    lbl_clrpion->setText("Choisir la couleur de votre Pion :");
    btn_CreerJr->setText("C&reer");
    btn_Commencer->setText("&Commencer");

    lbl_pseudo->move(panel->width()/10,panel->height()/4 - lbl_pseudo->height()/2);
    txt_Pseudo->move(panel->width()/10+lbl_pseudo->width()+30,panel->height()/4 - lbl_pseudo->height()/2);
    lbl_clrpion->move(panel->width()/10+40,panel->height()/2 - lbl_clrpion->height()/2);
    cbx_ClrPion->move(panel->width()/10+40+lbl_clrpion->width()+50,panel->height()/2 - lbl_clrpion->height()/2);
    btn_Commencer->move(65,panel->height()-1.5*btn_Commencer->height());
    btn_CreerJr->move(panel->width()-1.5*btn_CreerJr->width(),panel->height()-1.5*btn_Commencer->height());

}

void panel_creationJrs::afficher_panel_creationJrs(QGridLayout* layout)
{
    layout->addWidget(panel,1,1,Qt::AlignVCenter | Qt::AlignHCenter);

    parent->setLayout(layout);

    QWidget::connect(btn_CreerJr,SIGNAL(clicked()),this,SLOT(recuperer_infosJr()));
    QWidget::connect(btn_Commencer,SIGNAL(clicked()),mainWindow,SLOT(commencer_partie()));
}

void panel_creationJrs::recuperer_infosJr()
{
    bool empty = txt_Pseudo->text().isEmpty() || cbx_ClrPion->currentText()=="";
    if(empty)
        return;

    std::string pseudo = txt_Pseudo->text().toStdString();
    std::string couleur = cbx_ClrPion->currentText().toStdString();

    txt_Pseudo->setText(QString::null);
    cbx_ClrPion->removeItem(cbx_ClrPion->currentIndex());
    cbx_ClrPion->setCurrentIndex(0);

    QWidget::connect(this,SIGNAL(btn_CreerJr_Clicked(std::string,std::string)),
                     mainWindow,SLOT(initialiser_plateauDuJeu(std::string,std::string)));    
    static int n = 0;
    emit btn_CreerJr_Clicked(pseudo,couleur);
    QWidget::disconnect(this,SIGNAL(btn_CreerJr_Clicked(std::string,std::string)),
                        mainWindow,SLOT(initialiser_plateauDuJeu(std::string,std::string)));
    n++;
    if(n>=2)
        btn_Commencer->setVisible(true);
    else
        btn_Commencer->setVisible(false);
    if(n>=4)
    {
        txt_Pseudo->setEnabled(false);
        cbx_ClrPion->setEnabled(false);
        btn_CreerJr->setVisible(false);
    }
}

panel_creationJrs::~panel_creationJrs()
{
    delete panel;
}
