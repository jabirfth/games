#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QMainWindow>

typedef enum { INITIAL=-1,IN_GAME=0,GAME_OVER=1 } etat_plateau;

#include "../ObjetsGL/damiergl.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    GLWidget(QMainWindow* fenetre = 0, QWidget *parent = 0);
    void initializeGL();
    void resizeGL(int w,int h);
    void paintGL();

    etat_plateau getEtat() { return e; }
    void setEtat(etat_plateau);
    void setId_Pion(int n){ id_pion=n;}
    void setPosTo(int n){ posTo=n; }
    void setValeurDe(int n) { valDe = n; }

    void construireDe(int);
    void afficher_de();
    void deplacer(){deplacer_pion=true;}

    DamierGL *damier;

public slots:
    //void afficher_de();
    void set_timerOnOff(bool);

signals:
    void de_lance();
    void S_finanimation();
    void S_findeplacement(int,int);


private:
    etat_plateau e;

    GLuint faces_txt[6];
    bool masquer_de;
    bool deplacer_pion;

    int id_pion;
    int posTo;
    int valDe;
    QMainWindow *mainWindow;

    QTimer *timer_jeu;
};

#endif // GLWIDGET_H
