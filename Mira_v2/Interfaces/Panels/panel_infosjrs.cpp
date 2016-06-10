#include "panel_infosjrs.h"
#include "ui_panel_infosjrs.h"

panel_InfosJrs::panel_InfosJrs(QWidget *parent, QMainWindow *fenetre) :
    QWidget(parent),
    mainWindow(fenetre)
{
    panel = new QFrame;
    panel->setMinimumSize(315, 570);
    panel->setMaximumSize(315, 570);
    panel->setStyleSheet("background-color: rgb(229, 229, 229);");

    tabWidget = new QTabWidget(panel);
    tabWidget->setGeometry(QRect(16, 0, 300, 570));
    tabWidget->setMinimumSize(QSize(300, 570));
    tabWidget->setMaximumSize(QSize(300, 570));
    QFont font;
    font.setPointSize(16);
    tabWidget->setFont(font);
    tabWidget->setStyleSheet("background-color: rgb(193, 193, 193);");
    tabWidget->setTabPosition(QTabWidget::West);
    tabWidget->setTabShape(QTabWidget::Triangular);
    QHBoxLayout *layout = new QHBoxLayout();
    tabWidget->setLayout(layout);

    btn_MasquerPanel = new QPushButton(panel);
    btn_MasquerPanel->setObjectName(QString::fromUtf8("btn_MasquerPanel"));
    btn_MasquerPanel->setGeometry(QRect(1, 1, 14, 30));
    btn_MasquerPanel->setMinimumSize(QSize(14, 30));
    btn_MasquerPanel->setMaximumSize(QSize(14, 30));
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/images/divers/masquer"), QSize(), QIcon::Normal, QIcon::Off);
    btn_MasquerPanel->setIcon(icon);
    btn_MasquerPanel->setIconSize(QSize(64, 64));
    btn_MasquerPanel->setVisible(false);

    btn_AfficherPanel = new QPushButton(panel);
    btn_AfficherPanel->setObjectName(QString::fromUtf8("btn_AfficherPanel"));
    btn_AfficherPanel->setGeometry(QRect(1, 31, 14, 30));
    btn_AfficherPanel->setMinimumSize(QSize(14, 30));
    btn_AfficherPanel->setMaximumSize(QSize(14, 30));
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/images/divers/afficher"), QSize(), QIcon::Normal, QIcon::Off);
    btn_AfficherPanel->setIcon(icon1);
    btn_AfficherPanel->setIconSize(QSize(64, 64));

    tabWidget->setCurrentIndex(-1);

    tab_jr = new tab_ficheJr[4];
    connect(btn_AfficherPanel,SIGNAL(clicked()),this,SLOT(derouler()));
    connect(btn_MasquerPanel,SIGNAL(clicked()),this,SLOT(enrouler()));
    connect(tabWidget,SIGNAL(currentChanged(int)),this,SLOT(derouler()));
}

void panel_InfosJrs::afficher_panel_infoJrs(QGridLayout* layout, bool visible)
{
    panel->setVisible(visible);
    layout->addWidget(panel,1,2,Qt::AlignHCenter | Qt::AlignRight);
}

void panel_InfosJrs::update_info(int id, int pos)
{
    tab_jr[jr_index[id-1]].setPosPion(pos);


}

void panel_InfosJrs::creer_ficheJr(QString psd,int clr)
{
    QIcon icon;
    icon.addFile(QString(":/images/pions/%1").arg(clr), QSize(128,128), QIcon::Normal, QIcon::Off);
    static int n = 0;
    if(n<=0)
        tabWidget->clear();
    if(n>3)
        return;

    tab_jr[n].setClrPion(clr);
    tab_jr[n].setParent(tabWidget);
    tabWidget->insertTab(n,&tab_jr[n],icon,psd);
    tabWidget->setCurrentIndex(-1);
    jr_index[clr-1] = n;
    n++;
}

void panel_InfosJrs::selectionner_tab(int id_jr)
{
    tabWidget->setCurrentIndex(jr_index[id_jr-1]);
}

void panel_InfosJrs::derouler()
{
    panel->setMinimumWidth(315);
    panel->setMaximumWidth(315);

    tabWidget->setTabPosition(QTabWidget::East);

    btn_AfficherPanel->setVisible(false);
    btn_MasquerPanel->setVisible(true);
}

void panel_InfosJrs::enrouler()
{
    panel->setMinimumWidth(50);
    panel->setMaximumWidth(50);

    tabWidget->setTabPosition(QTabWidget::West);

    btn_AfficherPanel->setVisible(true);
    btn_MasquerPanel->setVisible(false);
}

panel_InfosJrs::~panel_InfosJrs()
{
    delete panel;
    delete tabWidget;
    delete btn_AfficherPanel;
    delete btn_MasquerPanel;
}
