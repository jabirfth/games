#ifndef PANEL_DE_H
#define PANEL_DE_H

#include <QWidget>
#include <QtGui>

namespace Ui {
class panel_de;
}

class panel_de : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_de(QWidget*parent, QMainWindow*fenetre);
    ~panel_de();

    void afficher_panel_de(QGridLayout*,bool visible=true);
    Ui::panel_de *ui;

public slots:
    void disable_btn();
    void enable_btn();
    void rotateOneStep();

signals:
    void S_finanimation();
    
private:


    QMainWindow *mainWindow;
};

#endif // PANEL_DE_H
