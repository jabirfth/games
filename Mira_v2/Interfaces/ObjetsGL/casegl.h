#ifndef CASEGL_H
#define CASEGL_H

#include <QGLWidget>

class CaseGL
{
public:
    CaseGL() { }
    CaseGL(int,GLdouble,GLdouble,GLdouble);
    int getNumero() { return numero; }
    GLdouble* getCoord() { return coord; }
    void dessiner(GLdouble);


private:
    int numero;
    GLdouble coord[3]; //coordonées du centre de la case

};

#endif // CASEGL_H
