#include "casegl.h"

CaseGL::CaseGL(int a, GLdouble x, GLdouble y, GLdouble z)
{
    numero = a;
    coord[0] = x; coord[1]= y; coord[2] = z;
}

void CaseGL::dessiner(GLdouble dl)
{
    glBegin(GL_QUADS);
        glVertex3d(coord[0]-dl,coord[1],coord[2]+dl);
        glVertex3d(coord[0]+dl,coord[1],coord[2]+dl);
        glVertex3d(coord[0]+dl,coord[1],coord[2]-dl);
        glVertex3d(coord[0]-dl,coord[1],coord[2]-dl);
    glEnd();
}
