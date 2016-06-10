#ifndef TAB_FICHEJR_H
#define TAB_FICHEJR_H

#include <QWidget>
#include <QtGui>

namespace Ui {
class tab_ficheJr;
}

class tab_ficheJr : public QWidget
{
    Q_OBJECT
    
public:
    explicit tab_ficheJr(QWidget *parent = 0);
    ~tab_ficheJr();

    void setPosPion(int);
    void setClassement(int);

public slots:
    void setClrPion(int);

signals:
    void Sg_setClrPion(int);
    
private:
    Ui::tab_ficheJr *ui;
    int clr;

};

#endif // TAB_FICHEJR_H
