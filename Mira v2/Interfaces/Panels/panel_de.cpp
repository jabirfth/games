#include "panel_de.h"
#include "ui_panel_de.h"

panel_de::panel_de(QWidget *parent, QMainWindow *fenetre) :
    QWidget(parent),
    ui(new Ui::panel_de),
    mainWindow(fenetre)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), ui->widget, SLOT(updateGL()));
    timer->start(10);


    ui->widget->rotateBy(+42 * 16, +42 * 16, -21 * 16);

    connect(ui->btn_LancerDe,SIGNAL(clicked()),this,SLOT(disable_btn()));
}

void panel_de::rotateOneStep()
{
    static bool first = true;
    static QTimer *timer = new QTimer(this);
    if(first)
    {
        connect(timer, SIGNAL(timeout()), this, SLOT(rotateOneStep()));
        timer->start(20);
        first = false;
    }
    ui->widget->rotateBy(+2 * 16, +2 * 16, -1 * 16);
}

void panel_de::afficher_panel_de(QGridLayout* layout, bool visible)
{
    ui->panel->setVisible(visible);
    layout->addWidget(this,0,2,Qt::AlignHCenter | Qt::AlignRight);

    QWidget::connect(ui->btn_LancerDe,SIGNAL(clicked()),mainWindow,SLOT(de_a_lancer()));
    QWidget::connect(ui->btn_LancerDe,SIGNAL(clicked()),this,SLOT(disable_btn()));
}

void panel_de::disable_btn()
{
    ui->btn_LancerDe->setEnabled(false);
}

void panel_de::enable_btn()
{
    ui->btn_LancerDe->setEnabled(true);
}

panel_de::~panel_de()
{
    delete ui;
}
