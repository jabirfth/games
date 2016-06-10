#include "damiergl.h"

#include <QGLWidget>
#include <cmath>

DamierGL::DamierGL(int a)
{
    finDeplacement=false;
    deplacer=false;
    deplacerS=false;
    cote = a;
    setCoord(0,-(GLdouble)cote/2.0,0,(GLdouble)cote/2.0);
    setCoord(1,(GLdouble)cote/2.0,0,(GLdouble)cote/2.0);
    setCoord(2,(GLdouble)cote/2.0,0,-(GLdouble)cote/2.0);
    setCoord(3,-(GLdouble)cote/2.0,0,-(GLdouble)cote/2.0);

    cases = new CaseGL[101];

    for(int ligne=1;ligne <= 10 ; ligne++)
    {
        for(int col=1;col<=10;col++)
        {
            int pos = (ligne%2)?ligne*10-10+col:10*ligne-col+1;
            GLdouble x = coord[0][0] + (GLdouble)cote/20.0 + (col-1)*(GLdouble)cote/10.0;
            GLdouble y = 0.0 ;
            GLdouble z = -(ligne-1)*(GLdouble)cote/10.0 + coord[0][2]-(GLdouble)cote/20.0 ;

            cases[pos] = CaseGL(pos,x,y,z);
        }
    }

    cases[0] = CaseGL(0,cases[1].getCoord()[0],
            cases[1].getCoord()[1],
            cases[1].getCoord()[2] + 1.5 * (GLdouble)cote/20.0);

    for(int i=0;i<4;i++)
        pions[i] = 0;



}

void DamierGL::setCoord(int c,GLdouble x,GLdouble y,GLdouble z)
{
    coord[c][0] = x;
    coord[c][1] = y;
    coord[c][2] = z;
}

void DamierGL::setTxt_Damier(QString path)
{
    txt_damier = bindTexture(QPixmap(QString(path)),GL_TEXTURE_2D);
}

void DamierGL::setTxt_corner(QString path)
{
    txt_corner = bindTexture(QPixmap(QString(path)),GL_TEXTURE_2D);
}

void DamierGL::creerPion(int clr)
{
    pions[clr-1] = new PionGL(clr);
    placerHorsJeu(clr);

}

void DamierGL::placerHorsJeu(int n)
{
    pions[n-1]->setCoord(cases[0].getCoord()[0] +  (n-1) * (GLdouble)cote/20.0,
            cases[0].getCoord()[1], cases[0].getCoord()[2]);
    pions[n-1]->setPosActuel(0);
}

void DamierGL::placerEnJeu(int n)
{
    pions[n-1]->setCoord(cases[1].getCoord()[0],cases[1].getCoord()[1],cases[1].getCoord()[2]);
    pions[n-1]->setPosActuel(1);
}

void DamierGL::deplacerPion(int n, int posTo)
{
    if(deplacer)
    {
        if(n<0)
            return;
        PionGL *p = pions[n-1];
        int posFrom = p->getPosActuel();
        if(posFrom == 0)
        {
            placerEnJeu(n);
            return;
        }

        static GLdouble dx=0,dz=0;
        static bool first=true;



        if(first)
        {
            for(int i=0;i<4;i++)
            {
                if(pions[i] && pions[i]->getPosActuel()==posTo)
                {
                    placerHorsJeu(i+1);
                }
            }
            p->deplacerJusqu(cases[posTo].getCoord()[0],cases[posTo].getCoord()[2]);
            int ligne=(posFrom%10)?posFrom/10:posFrom/10+1;
            dx = (ligne%2)?-1:1;
            bool avancer=(posFrom<posTo)?true:false;
            dx=(avancer)?dx:-dx;
            dz = -1;
            first = false;
        }

        GLdouble x=p->Coord()[0],y=p->Coord()[1],z=p->Coord()[2];

        if(p->aDeplacer())
        {
            x += dx*0.05;
            if(x > (GLdouble)cote/2.0 - (GLdouble)cote/20.0)
            {
                z += dz*(GLdouble)cote/10.0;
                dx *= -1;
            }
            else if(x < -(GLdouble)cote/2.0 + (GLdouble)cote/20.0)
            {
                z += dz*(GLdouble)cote/10.0;
                dx *= -1;
            }
        }
        else
        {
            dx = 0; dz = 0;
            first = true;
            finDeplacement=true;
            p->setPosActuel(posTo);
            deplacer=false;
        }
        p->setCoord(x,y,z);
    }
    if(deplacerS)
    {
        PionGL *p = pions[n-1];
        int posFrom = pions[n-1]->getPosActuel();
        CaseGL *c1=&cases[posFrom],*c2=&cases[posTo];
        GLdouble x=p->Coord()[0],y=p->Coord()[1],z=p->Coord()[2];
        static GLdouble dx=0,dz=0;
        static bool first=true;
        if(first)
        {
            for(int i=0;i<4;i++)
            {
                if(pions[i] && pions[i]->getPosActuel()==posTo)
                    placerHorsJeu(i+1);
            }
            bool monter=(c1->getCoord()[2]<=c2->getCoord()[2])?true:false;
            dz = (monter)?(z-c2->getCoord()[2])/100:(c2->getCoord()[2]-z)/100;
            dz *= (monter)?-1:1;
            bool leftToRight = (c1->getCoord()[0]<=c2->getCoord()[0])?true:false;
            dx =(leftToRight)?(c2->getCoord()[0] - x)/100:(x - c2->getCoord()[0])/100;
            dx *=(leftToRight)?1:-1;
            first = false;
        }

        if(fabs(x-c2->getCoord()[0])<0.000001 && fabs(z - c2->getCoord()[2])<0.000001 )
        {
            dz=0;   dx=0;
            p->setPosActuel(posTo);
            p->setCoord(x,y,z);
            first = true;
            deplacerS=false;
            deplacer=false;
            finDeplacement=true;
        }
        else
        {
            x += dx;
            z += dz;
            p->setCoord(x,y,z);
        }
    }
}


void DamierGL::dessiner(bool afficherPion)
{
    for(int i=1;i<=100;i++)
    {
        glColor3ub(255,100*(i%2)+55,255);
        cases[i].dessiner(cote/20);
    }

    glColor3ub(255,255,255);
    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, txt_damier);
    glBegin(GL_QUADS);
        /* A-a */glTexCoord2d(0,0); glVertex3d(coord[0][0],coord[0][1],coord[0][2]);
        /* B-b */glTexCoord2d(1,0); glVertex3d(coord[1][0],coord[1][1],coord[1][2]);
        /* C-c */glTexCoord2d(1,1); glVertex3d(coord[2][0],coord[2][1],coord[2][2]);
        /* D-d */glTexCoord2d(0,1); glVertex3d(coord[3][0],coord[3][1],coord[3][2]);
    glEnd();

    glBindTexture(GL_TEXTURE_2D,txt_corner);
    glBegin(GL_QUADS);
        //-1 abcd
        /* a */glTexCoord2d(0,0); glVertex3d(coord[0][0]-cote/10,coord[0][1]-.1,coord[0][2]+cote/10);
        /* b */glTexCoord2d(10,0); glVertex3d(coord[1][0]+cote/10,coord[1][1]-.1,coord[1][2]+cote/10);
        /* c */glTexCoord2d(10,10); glVertex3d(coord[2][0]+cote/10,coord[2][1]-.1,coord[2][2]-cote/10);
        /* d */glTexCoord2d(0,10); glVertex3d(coord[3][0]-cote/10,coord[3][1]-.1,coord[3][2]-cote/10);

        //1L AA'D'D
        /* A */glTexCoord2d(0,0); glVertex3d(coord[0][0]-cote/10,coord[0][1]+.1,coord[0][2]+cote/10);
        /* A' */glTexCoord2d(1,0); glVertex3d(coord[0][0],coord[0][1]+.1,coord[0][2]);
        /* D' */glTexCoord2d(1,10); glVertex3d(coord[3][0],coord[3][1]+.1,coord[3][2]);
        /* D */glTexCoord2d(0,10); glVertex3d(coord[3][0]-cote/10,coord[3][1]+.1,coord[3][2]-cote/10);

        //1T D'C'CD
         /* D' */glTexCoord2d(0,0); glVertex3d(coord[3][0],coord[3][1]+.1,coord[3][2]);
        /* C' */glTexCoord2d(10,0); glVertex3d(coord[2][0],coord[2][1]+.1,coord[2][2]);
        /* C */glTexCoord2d(10,1); glVertex3d(coord[2][0]+cote/10,coord[2][1]+.1,coord[2][2]-cote/10);
        /* D */ glTexCoord2d(0,1); glVertex3d(coord[3][0]-cote/10,coord[3][1]+.1,coord[3][2]-cote/10);

        //1R B'BCC'
        /* B' */glTexCoord2d(0,0); glVertex3d(coord[1][0],coord[1][1]+.1,coord[1][2]);
        /* B */glTexCoord2d(1,0); glVertex3d(coord[1][0]+cote/10,coord[1][1]+.1,coord[1][2]+cote/10);
        /* C */glTexCoord2d(1,10); glVertex3d(coord[2][0]+cote/10,coord[2][1]+.1,coord[2][2]-cote/10);
        /* C' */glTexCoord2d(0,10); glVertex3d(coord[2][0],coord[2][1]+.1,coord[2][2]);

        //1B ABB'A'
        /* A */glTexCoord2d(0,0); glVertex3d(coord[0][0]-cote/10,coord[0][1]+.1,coord[0][2]+cote/10);
        /* B */ glTexCoord2d(10,0); glVertex3d(coord[1][0]+cote/10,coord[1][1]+.1,coord[1][2]+cote/10);
        /* B' */glTexCoord2d(10,1); glVertex3d(coord[1][0],coord[1][1]+.1,coord[1][2]);
        /* A' */glTexCoord2d(0,1); glVertex3d(coord[0][0],coord[0][1]+.1,coord[0][2]);

        //0L ADda
        /* A */glTexCoord2d(1,0); glVertex3d(coord[0][0]-cote/10,coord[0][1]+.1,coord[0][2]+cote/10);
        /* D */glTexCoord2d(0,10); glVertex3d(coord[3][0]-cote/10,coord[3][1]+.1,coord[3][2]-cote/10);
        /* d */glTexCoord2d(1,10); glVertex3d(coord[3][0]-cote/10,coord[3][1]-.1,coord[3][2]-cote/10);
        /* a */glTexCoord2d(0,10); glVertex3d(coord[0][0]-cote/10,coord[0][1]-.1,coord[0][2]+cote/10);

        //0T DCcd
        /* D */glTexCoord2d(0,0); glVertex3d(coord[3][0]-cote/10,coord[3][1]+.1,coord[3][2]-cote/10);
        /* C */glTexCoord2d(10,0); glVertex3d(coord[2][0]+cote/10,coord[2][1]+.1,coord[2][2]-cote/10);
        /* c */glTexCoord2d(10,1); glVertex3d(coord[2][0]+cote/10,coord[2][1]-.1,coord[2][2]-cote/10);
        /* d */glTexCoord2d(0,1); glVertex3d(coord[3][0]-cote/10,coord[3][1]-.1,coord[3][2]-cote/10);
        //0R BCcb
        /* B */glTexCoord2d(0,0); glVertex3d(coord[1][0]+cote/10,coord[1][1]+.1,coord[1][2]+cote/10);
        /* C */glTexCoord2d(0,10); glVertex3d(coord[2][0]+cote/10,coord[2][1]+.1,coord[2][2]-cote/10);
        /* c */glTexCoord2d(1,10); glVertex3d(coord[2][0]+cote/10,coord[2][1]-.1,coord[2][2]-cote/10);
        /* b */glTexCoord2d(1,0); glVertex3d(coord[1][0]+cote/10,coord[1][1]-.1,coord[1][2]+cote/10);
        //0B ABba
        /* A */glTexCoord2d(0,1); glVertex3d(coord[0][0]-cote/10,coord[0][1]+.1,coord[0][2]+cote/10);
        /* B */glTexCoord2d(10,1); glVertex3d(coord[1][0]+cote/10,coord[1][1]+.1,coord[1][2]+cote/10);
        /* b */glTexCoord2d(10,0); glVertex3d(coord[1][0]+cote/10,coord[1][1]-.1,coord[1][2]+cote/10);
        /* a */glTexCoord2d(0,0); glVertex3d(coord[0][0]-cote/10,coord[0][1]-.1,coord[0][2]+cote/10);

    glEnd();

    glPopMatrix();

    if(afficherPion)
    {
        for(int i=0;i<4;i++)
        {
            if(pions[i])
            {
                glPushMatrix();// pour dessiner le pion
                    pions[i]->dessiner((GLdouble)cote/40.0);
                glPopMatrix();
            }
        }
    }

//    glBegin(GL_POINTS);
//    /* A */glVertex3d(coord[0][0]-cote/10,coord[0][1]+.1,coord[0][2]+cote/10);
//    /* B */glVertex3d(coord[1][0]+cote/10,coord[1][1]+.1,coord[1][2]+cote/10);
//    /* C */glVertex3d(coord[2][0]+cote/10,coord[2][1]+.1,coord[2][2]-cote/10);
//    /* D */glVertex3d(coord[3][0]-cote/10,coord[3][1]+.1,coord[3][2]-cote/10);

//    /* A' */glVertex3d(coord[0][0],coord[0][1]+.1,coord[0][2]);
//    /* B' */glVertex3d(coord[1][0],coord[1][1]+.1,coord[1][2]);
//    /* C' */glVertex3d(coord[2][0],coord[2][1]+.1,coord[2][2]);
//    /* D' */glVertex3d(coord[3][0],coord[3][1]+.1,coord[3][2]);

//    /* A-a */glVertex3d(coord[0][0],coord[0][1],coord[0][2]);
//    /* B-b */glVertex3d(coord[1][0],coord[1][1],coord[1][2]);
//    /* C-c */glVertex3d(coord[2][0],coord[2][1],coord[2][2]);
//    /* D-d */glVertex3d(coord[3][0],coord[3][1],coord[3][2]);

//    /* a */glVertex3d(coord[0][0]-cote/10,coord[0][1]-.1,coord[0][2]+cote/10);
//    /* b */glVertex3d(coord[1][0]+cote/10,coord[1][1]-.1,coord[1][2]+cote/10);
//    /* c */glVertex3d(coord[2][0]+cote/10,coord[2][1]-.1,coord[2][2]-cote/10);
//    /* d */glVertex3d(coord[3][0]-cote/10,coord[3][1]-.1,coord[3][2]-cote/10);

//    /* a' */glVertex3d(coord[0][0],coord[0][1]-.1,coord[0][2]);
//    /* b' */glVertex3d(coord[1][0],coord[1][1]-.1,coord[1][2]);
//    /* c' */glVertex3d(coord[2][0],coord[2][1]-.1,coord[2][2]);
//    /* d' */glVertex3d(coord[3][0],coord[3][1]-.1,coord[3][2]);

//    glEnd();

}
