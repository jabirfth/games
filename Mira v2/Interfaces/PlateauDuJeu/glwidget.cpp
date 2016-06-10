#include "glwidget.h"

#include <QTimer>
#include <GL/glu.h>
#include <cmath>


GLWidget::GLWidget(QMainWindow *fenetre,QWidget *parent) :
    QGLWidget(parent),mainWindow(fenetre)
{
    e=INITIAL;
    damier = new DamierGL(15);

    masquer_de = true;
    deplacer_pion=false;

    timer_jeu = new QTimer(this);
    connect(timer_jeu, SIGNAL(timeout()), this, SLOT(updateGL()));
    timer_jeu->start(20);
}

void GLWidget::set_timerOnOff(bool on)
{
    if(on)
        timer_jeu->start(20);
    else
        timer_jeu->stop();
}

void GLWidget::setEtat(etat_plateau e)
{
    this->e = e;
    updateGL();
}

void GLWidget::afficher_de()
{
    masquer_de = false;
}

void GLWidget::initializeGL()
{
    qglClearColor(Qt::black);
    glEnable(GL_DEPTH_TEST);
}

void GLWidget::construireDe(int a)
{
    QVector<int> v;
    for(int i=1;i<=6;i++)
    {
        if(a==i)
        {
            faces_txt[5] = bindTexture(QPixmap(QString(":/images/des/face%1").arg(a)), GL_TEXTURE_2D);
            faces_txt[a-1] = bindTexture(QPixmap(QString(":/images/des/face%1").arg(6)), GL_TEXTURE_2D);
        }
        else if(i==6)
            continue;
        else
            faces_txt[i-1] = bindTexture(QPixmap(QString(":/images/des/face%1").arg(i)), GL_TEXTURE_2D);
    }
}

void GLWidget::resizeGL(int w, int h)
{
    w=this->parentWidget()->w();
    h = this->parentWidget()->h();

    glViewport(0,0,(GLsizei)w,(GLsizei)h);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(50,(GLdouble)w/(GLdouble)h, .1,45);
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::paintGL()
{
    static GLdouble angle1=0,angle2=0,shift=0;
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    switch(e)
    {
    case INITIAL:
        damier->setTxt_Damier(":/images/damiers/3");
        damier->setTxt_corner(":/images/textures/1");

        glLoadIdentity();
        glPushMatrix();

            glTranslated(0,0,-shift);
            shift += (shift>=20)?0:0.2;
            glRotated(angle1-30*deplacer_pion,1,0,0);
            angle1 +=(angle1>=30)?0:0.2;
            glRotated(angle2,0,1,0);
            angle2+=(angle2>=360)?0:1.0;



            glPushMatrix();
                damier->dessiner(true);
            glPopMatrix();

            glPushMatrix();
            glPopMatrix();

        glPopMatrix();
        break;
    case IN_GAME:
        damier->setTxt_Damier(":/images/damiers/3");
        damier->setTxt_corner(":/images/textures/1");

        if(deplacer_pion)
            damier->deplacerPion(id_pion,posTo);

        if(damier->getfinDeplacement())
        {
            damier->setfinDeplacement();
            deplacer_pion=false;
            connect(this,SIGNAL(S_findeplacement(int,int)),mainWindow,SLOT(findepelacementN(int,int)));
            emit S_findeplacement(id_pion,posTo);
            disconnect(SIGNAL(S_findeplacement(int,int)));
        }


        static bool stopL=false,stopG=false;
        static int i=0;
        static GLdouble x=7.5,y=7.5,z=-7.5;
        static GLdouble dx =0;

        glLoadIdentity();

        glPushMatrix();

            glTranslated(0,0,-shift);
            shift += (shift>=30)?0:0.5;
            glRotated(angle1,1,0,0);
            angle1 +=(angle1>=60)?0:0.5;

            glScaled(2,1,1.5);

            glPushMatrix();//pour dessiner le damier
                damier->dessiner(true);

            if(!masquer_de) {
            glPushMatrix();// pour dessiner le des
                construireDe(valDe);
                static GLdouble dim=0.3;

                dx += (dx<=2*360)?2.5:0;

                stopL = (y < 1)?true:false;
                stopG = (dx>2*360 && stopL)?true:false;

                if(!stopL && !stopG)
                {
                    glTranslated(x,y+1,z);
                    glRotated(dx,1,0,0);
                    glRotated(dx,0,1,0);
                    glRotated(dx,0,0,1);
                    x-=0.05;   y-=0.05;  z+=0.05;
                }
                else
                {
                    if(!stopG)
                    {                        
                        glTranslated(x,y+1,z);
                        glRotated(dx,1,0,1);
                        x -= .03;
                        y =.1;
                        z += .03;
                        dx += (dx<=2*360)?1.5:0;
                    }
                    else
                    {
                        i++;
                        glTranslated(x,y,z);
                        masquer_de = (i>3000/20)?true:false;
                        if(masquer_de)
                        {
                            emit S_finanimation();

                            disconnect(SIGNAL(S_finanimation()));
                        }
                    }
                }
                glScaled(1,1,1);

                glEnable(GL_TEXTURE_2D);
                glBindTexture(GL_TEXTURE_2D,faces_txt[0]);
                glColor3ub(255,255,255);
                glBegin(GL_QUADS);
                    glTexCoord2d(0,0); glVertex3d(-dim,-dim,dim);
                    glTexCoord2d(1,0); glVertex3d(dim,-dim,dim);
                    glTexCoord2d(1,1); glVertex3d(dim,dim,dim);
                    glTexCoord2d(0,1); glVertex3d(-dim,dim,dim);
                glEnd();

                glBindTexture(GL_TEXTURE_2D,faces_txt[1]);
                glBegin(GL_QUADS);
                    glTexCoord2d(0,0); glVertex3d(dim,-dim,dim);
                    glTexCoord2d(1,0); glVertex3d(dim,-dim,-dim);
                    glTexCoord2d(1,1); glVertex3d(dim,dim,-dim);
                    glTexCoord2d(0,1); glVertex3d(dim,dim,dim);
                glEnd();


                glBindTexture(GL_TEXTURE_2D,faces_txt[2]);
                glBegin(GL_QUADS);
                    glTexCoord2d(0,1); glVertex3d(-dim,-dim,-dim);
                    glTexCoord2d(1,1); glVertex3d(dim,-dim,-dim);
                    glTexCoord2d(1,0); glVertex3d(dim,dim,-dim);
                    glTexCoord2d(0,0); glVertex3d(-dim,dim,-dim);
                glEnd();

                glBindTexture(GL_TEXTURE_2D,faces_txt[3]);
                glBegin(GL_QUADS);
                    glTexCoord2d(0,0); glVertex3d(-dim,-dim,dim);
                    glTexCoord2d(1,0); glVertex3d(-dim,-dim,-dim);
                    glTexCoord2d(1,1); glVertex3d(-dim,dim,-dim);
                    glTexCoord2d(0,1); glVertex3d(-dim,dim,dim);
                glEnd();

                glBindTexture(GL_TEXTURE_2D,faces_txt[4]);
                glBegin(GL_QUADS);
                    glTexCoord2d(0,1); glVertex3d(-dim,-dim,dim);
                    glTexCoord2d(1,1); glVertex3d(dim,-dim,dim);
                    glTexCoord2d(1,0); glVertex3d(dim,-dim,-dim);
                    glTexCoord2d(0,0); glVertex3d(-dim,-dim,-dim);
                glEnd();

                glBindTexture(GL_TEXTURE_2D,faces_txt[5]);
                glBegin(GL_QUADS);
                    glTexCoord2d(0,0); glVertex3d(-dim,dim,dim);
                    glTexCoord2d(1,0); glVertex3d(dim,dim,dim);
                    glTexCoord2d(1,1); glVertex3d(dim,dim,-dim);
                    glTexCoord2d(0,1); glVertex3d(-dim,dim,-dim);
                glEnd();
                glDisable(GL_TEXTURE_2D);
            glPopMatrix();
            }
            else
            {
                x=7.5;y=7.5;z=-7.5;
                dx=0;
                stopL = false;stopG=false;
                i=0;
            }


        glPopMatrix();
        break;
    case GAME_OVER:
        break;
    }
}
