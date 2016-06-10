#ifndef PANEL_CREATIONJRS_H
#define PANEL_CREATIONJRS_H

#include <QtGui>
#include <QWidget>

class panel_creationJrs : public QWidget
{
    Q_OBJECT
    
public:
    explicit panel_creationJrs(QWidget*,QMainWindow*);
    ~panel_creationJrs();

    void afficher_panel_creationJrs(QGridLayout *);

public slots:
    void recuperer_infosJr();

signals:
    void btn_CreerJr_Clicked(std::string,std::string);
    
private:
    QFrame *panel;
    QLabel *lbl_pseudo;
    QLineEdit *txt_Pseudo;
    QLabel *lbl_clrpion;
    QComboBox *cbx_ClrPion;
    QPushButton *btn_CreerJr;
    QPushButton *btn_Commencer;
    QPushButton *btn_home;

    QWidget* parent;
    QMainWindow *mainWindow;
};

#endif // PANEL_CREATIONJRS_H
