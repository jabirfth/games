#ifndef CADRE_POS_PION_H
#define CADRE_POS_PION_H

#include <QGLWidget>


#include <QGLWidget>

#include "../ObjetsGL/piongl.h"

QT_FORWARD_DECLARE_CLASS(QGLShaderProgram);

class cadre_pos_pion : public QGLWidget
{
    Q_OBJECT

public:
    explicit cadre_pos_pion(QWidget *parent = 0);
    ~cadre_pos_pion();

    void rotateBy(int xAngle, int yAngle, int zAngle);
    void setClearColor(const QColor &color);

public slots:
    void setClrPion(int);

signals:
    void clicked();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:
    int clr_pion;
    QColor clearColor;
    GLdouble yRot;
    PionGL *pion;

};

#endif // CADRE_POS_PION_H
