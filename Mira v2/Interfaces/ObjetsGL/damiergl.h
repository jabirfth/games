#ifndef DAMIERGL_H
#define DAMIERGL_H

#include <QGLWidget>
#include <QString>

#include "casegl.h"
#include "piongl.h"


class DamierGL : public QGLWidget
{
    Q_OBJECT
public:
    DamierGL() { }
    DamierGL(int);

    int Cote() { return cote; }
    GLdouble* Coord(int i) { return coord[i]; }
    void setCoord(int,GLdouble,GLdouble,GLdouble);
    GLuint Txt_Damier() { return txt_damier; }
    void setTxt_Damier(QString);
    GLuint Txt_corner() { return txt_corner; }
    void setTxt_corner(QString);

    CaseGL Cases(int n) { return cases[n]; }
    PionGL* Pion(int n) { return pions[n-1]; }

    void creerPion(int);

    void dessiner(bool afficherPion=false);

    void deplacerPion(int,int);
    void placerHorsJeu(int);
    void placerEnJeu(int);
    bool getfinDeplacement() {return finDeplacement;}
    void setfinDeplacement() {finDeplacement=false;}


    bool getdeplacer() {return deplacer;}
    void setdeplacer() {deplacer=true;}

    bool getdeplacerS() {return deplacerS;}
    void setdeplacerS() {deplacerS=true;}

private:
    int cote;
    GLdouble coord[4][3];//coordonnées des 4corners
    CaseGL *cases;    
    PionGL* pions[4];

    GLuint txt_damier;
    GLuint txt_corner;
    bool finDeplacement;
    bool deplacer;
    bool deplacerS;
};

#endif // DAMIERGL_H
