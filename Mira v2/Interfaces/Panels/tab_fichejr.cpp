#include "tab_fichejr.h"
#include "ui_tab_fichejr.h"

tab_ficheJr::tab_ficheJr(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::tab_ficheJr)
{
    ui->setupUi(this);

    setPosPion(0);
    setClassement(-1);


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), ui->widget, SLOT(updateGL()));
    timer->start(100);


    connect(this,SIGNAL(Sg_setClrPion(int)),ui->widget,SLOT(setClrPion(int)));
}

void tab_ficheJr::setPosPion(int a)
{
    ui->lbl_posPion->setText("<html><head/><body><p><span style=\" color:#616161; vertical-align:super;\">Case n </span><span style=\" font-size:20pt; font-weight:600; color:#000000; vertical-align:super;\">"
                             + QString::number(a) + "</span></p></body></html>");
}

void tab_ficheJr::setClrPion(int clr)
{
    this->clr = clr;
    emit Sg_setClrPion(clr);
}

void tab_ficheJr::setClassement(int a)
{
    QString str;
    if(a<0)
        str = "";
    else if(a==1)
        str = "1</span><span style=\" font-size:20pt; color:#aa0000; vertical-align:super;\">er";
    else
        str = QString::number(a) + "</span><span style=\" font-size:20pt; color:#aa0000; vertical-align:super;\">eme";
    ui->lbl_classement->setText("<html><head/><body><p><span style=\" font-size:20pt; color:#aa0000;\">" + str + "</span></p></body></html>");

}

tab_ficheJr::~tab_ficheJr()
{
    delete ui;
}
