#include "cadre_pos_pion.h"

#include <QtOpenGL>
#include <GL/glu.h>

#include "cadre_de.h"

cadre_pos_pion::cadre_pos_pion(QWidget *parent)
    : QGLWidget(parent)
{

    clearColor = Qt::black;
    yRot = 0;

    pion = new PionGL(clr_pion);

}

cadre_pos_pion::~cadre_pos_pion()
{
    delete pion;
}

void cadre_pos_pion::setClrPion(int a)
{
    clr_pion=a;
    pion->setColor(clr_pion);
}

void cadre_pos_pion::setClearColor(const QColor &color)
{
    clearColor = color;
}

void cadre_pos_pion::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void cadre_pos_pion::paintGL()
{
    qglClearColor(clearColor);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    yRot += 5;

    glLoadIdentity();
    glTranslated(0, -.5, -2);
    glRotated(30,1,0,0);
    glRotated(yRot,0,1,0);

    pion->setCoord(0,0.2,0);
    pion->dessiner(0.25);
}

void cadre_pos_pion::resizeGL(int width, int height)
{
    glViewport(0,0,(GLsizei)width,(GLsizei)height);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(50,(GLdouble)width/(GLdouble)height, .1,150);
    glMatrixMode(GL_MODELVIEW);
}

