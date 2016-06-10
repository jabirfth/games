#include "panel_horloge.h"
#include "ui_panel_horloge.h"

panel_Horloge::panel_Horloge(QWidget *parent, QMainWindow *fenetre) :
    QWidget(parent),
    ui(new Ui::panel_Horloge),
    mainWindow(fenetre)
{
    ui->setupUi(this);
    compteur = 0;
    setCompteurTxt(compteur);

    timerCmptr = new QTimer(this);
    connect(timerCmptr,SIGNAL(timeout()),this,SLOT(incrementTimer()));
    connect(ui->btn_pause,SIGNAL(clicked()),this,SLOT(btn_pause_clicked()));
    connect(this,SIGNAL(S_pause_game(bool)),mainWindow,SLOT(pause_game(bool)));
}

void panel_Horloge::btn_pause_clicked()
{
    if(ui->btn_pause->text()=="P \nA \nU \nS \nE")
    {
        emit S_pause_game(false);
        ui->btn_pause->setText("R \nE \nP \nR \nI");
    }
    else
    {
        emit S_pause_game(true);
        ui->btn_pause->setText("P \nA \nU \nS \nE");
    }
}

void panel_Horloge::afficher_panel_horloge(QGridLayout* layout, bool visible)
{
    ui->panel->setVisible(visible);
    layout->addWidget(this,0,0,Qt::AlignHCenter | Qt::AlignLeft);
}

void panel_Horloge::setTimerOnOff(bool on)
{
    if(on)
        timerCmptr->start(1000);
    else
        timerCmptr->stop();
}

void panel_Horloge::incrementTimer()
{
    setCompteurTxt(++compteur);
}

void panel_Horloge::setCompteurTxt(int a)
{
    int temp = a,h=0,m=0,s=0;
    QString H="00",M="00",S="00";

    h = temp/3600;
    temp -= h*3600;
    m = temp/60;
    temp -= m*60;
    s = temp;
    if(h>=0 && h<10)
        H = "0" + QString::number(h);
    else
        H=QString::number(h);
    if(m>=0 && m<10)
        M = "0" + QString::number(m);
    else
        M=QString::number(m);
    if(s>=0 && s<10)
        S = "0" + QString::number(s);
    else
        S=QString::number(s);

    ui->lbl_Compteur->setText(H + ":" + M + ":" + S );
}

panel_Horloge::~panel_Horloge()
{
    delete ui;
}
