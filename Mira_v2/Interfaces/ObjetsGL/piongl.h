#ifndef PIONGL_H
#define PIONGL_H

#include <QGLWidget>

class PionGL : public QGLWidget
{
    Q_OBJECT
public:
    PionGL(int c=0);
    int Couleur() { return clr; }
    GLdouble* Coord() { return coord; }
    void setCoord(GLdouble,GLdouble,GLdouble);
    GLdouble* CoordDest() { return coordDest; }
    void setColor(int c) { clr = c; }

    void setPosActuel(int a) { posActuel = a; }
    int getPosActuel() { return posActuel; }


    void dessiner(GLdouble);

    void deplacerJusqu(GLdouble, GLdouble);
    bool aDeplacer();

private:
    int clr;

    int posActuel;
    GLdouble coord[3];
    GLdouble dx;
    GLdouble dy;
    GLdouble dz;
    GLdouble coordDest[3];
};

#endif // PIONGL_H
