#include "piongl.h"

#include <cmath>

PionGL::PionGL(int c)
{
    clr = c;
    coord[0] = 0;   coord[1]=0.1; coord[2]=0;
    coordDest[0] = 0;   coordDest[1]=0; coordDest[2]=0;
    posActuel = 0;
}

void PionGL::setCoord(GLdouble x,GLdouble y,GLdouble z)
{
    coord[0] = x;   coord[1]=y; coord[2]=z;
}

void PionGL::deplacerJusqu(GLdouble x,GLdouble z)
{
    coordDest[0] = x; coordDest[1]=0; coordDest[2]=z;
}

bool PionGL::aDeplacer()
{
    bool X = fabs(coord[0]-coordDest[0])<0.000001;
    bool Z=fabs(coord[2] - coordDest[2])<0.000001;
    return (!(X &&Z));
}

void PionGL::dessiner(GLdouble r)
{
    if(coord[0]==0 && coord[1]==0.1 && coord[2]==0)
        return;

    GLuint tex = bindTexture(QPixmap(QString(":/images/pions/%1").arg(clr)),GL_TEXTURE_2D);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,tex);
    glColor3ub(255,255,255);
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2d(0.5,0.5); glVertex3f(coord[0],coord[1],coord[2]);
        for(GLdouble alpha=0;alpha<=360;alpha+=0.5)
        {
            glTexCoord2d(.8+cos(alpha),.5+sin(alpha));
            glVertex3d(coord[0] + r * cos(alpha),coord[1],coord[2] + r * sin(alpha));
        }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2d(0.5,0.5);
        glVertex3f(coord[0],coord[1],coord[2]);
        for(GLdouble alpha=0;alpha<=360;alpha+=0.5)
        {
            glTexCoord2d(.5+cos(alpha),.5-cos(alpha));
            glVertex3d(coord[0] + (GLdouble)r/2.0 * cos(alpha),1,coord[2] + (GLdouble)r/2.0 * sin(alpha));
        }

    glEnd();


    glBegin(GL_QUAD_STRIP);
        for(GLdouble alpha=0;alpha<=360;alpha+=0.5)
        {
            glTexCoord2d(.5+cos(alpha),.5-cos(alpha));
            glVertex3d(coord[0] + r * cos(alpha),coord[1],coord[2] + r * sin(alpha));
            glTexCoord2d(.5+sin(alpha),.5-sin(alpha));
            glVertex3d(coord[0] + (GLdouble)r/2.0 * cos(alpha),1,coord[2] + (GLdouble)r/2.0 * sin(alpha));
        }
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
