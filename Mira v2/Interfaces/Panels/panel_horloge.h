#ifndef PANEL_HORLOGE_H
#define PANEL_HORLOGE_H

#include <QtGui>
#include <QWidget>

namespace Ui {
class panel_Horloge;
}

class panel_Horloge : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_Horloge(QWidget *parent = 0,QMainWindow *fenetre=0);
    ~panel_Horloge();

    void afficher_panel_horloge(QGridLayout*,bool visible=true);
    void setCompteurTxt(int);
    
public slots:
    void incrementTimer();
    void setTimerOnOff(bool);
    void btn_pause_clicked();

signals:
    void S_pause_game(bool);

private:
    Ui::panel_Horloge *ui;
    int compteur;
    QTimer *timerCmptr;

    QMainWindow *mainWindow;
};

#endif // PANEL_HORLOGE_H
