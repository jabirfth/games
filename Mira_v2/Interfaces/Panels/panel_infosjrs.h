#ifndef PANEL_INFOSJRS_H
#define PANEL_INFOSJRS_H

#include <QWidget>
#include <QtGui>

#include "tab_fichejr.h"

class panel_InfosJrs : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_InfosJrs(QWidget*,QMainWindow*);
    ~panel_InfosJrs();

    void afficher_panel_infoJrs(QGridLayout*,bool visible=true);
    void creer_ficheJr(QString, int);
    void update_info(int,int);

public slots:
    void derouler();
    void enrouler();
    void selectionner_tab(int);
    
private:
    QFrame *panel;
    QTabWidget *tabWidget;
    QPushButton *btn_MasquerPanel;
    QPushButton *btn_AfficherPanel;

    tab_ficheJr *tab_jr;
    int jr_index[4];

    QMainWindow *mainWindow;
};

#endif // PANEL_INFOSJRS_H
