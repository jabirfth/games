#ifndef CADRE_DE_H
#define CADRE_DE_H

#include <QGLWidget>

QT_FORWARD_DECLARE_CLASS(QGLShaderProgram);

class cadre_de : public QGLWidget
{
    Q_OBJECT

public:
    explicit cadre_de(QWidget *parent = 0);
    ~cadre_de();

    void rotateBy(int xAngle, int yAngle, int zAngle);
    void setClearColor(const QColor &color);

signals:
    void clicked();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

private:
    void makeObject();

    QColor clearColor;
    int xRot;
    int yRot;
    int zRot;
    GLuint textures[6];
    QVector<QVector3D> vertices;
    QVector<QVector2D> texCoords;

};

#endif // CADRE_DE_H
