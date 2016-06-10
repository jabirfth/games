#-------------------------------------------------
#
# Project created by QtCreator 2013-05-26T23:47:19
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Echelle_Et_Serpent
TEMPLATE = app


SOURCES += main.cpp \
    Interfaces/fenetre_principale.cpp \
    Interfaces/ObjetsGL/damiergl.cpp \
    Interfaces/ObjetsGL/piongl.cpp \
    Interfaces/PlateauDuJeu/glwidget.cpp \
    Interfaces/Menus/menu_accueil.cpp \
    Interfaces/ObjetsGL/casegl.cpp \
    Interfaces/Panels/panel_creationjrs.cpp \
    Interfaces/Panels/panel_horloge.cpp \
    Interfaces/Panels/panel_infosjrs.cpp \
    Interfaces/Panels/tab_fichejr.cpp \
    Noyau/plateau_du_jeu.cpp \
    Noyau/pion.cpp \
    Noyau/partie.cpp \
    Noyau/joueur.cpp \
    Noyau/de.cpp \
    Noyau/damier.cpp \
    Noyau/case.cpp \
    Interfaces/PlateauDuJeu/cadre_de.cpp \
    Interfaces/Panels/panel_de.cpp \
    Controleur/controleur.cpp \
    Interfaces/PlateauDuJeu/cadre_pos_pion.cpp \
    Interfaces/Menus/menu_pause.cpp

HEADERS  += \
    Interfaces/fenetre_principale.h \
    Interfaces/ObjetsGL/damiergl.h \
    Interfaces/ObjetsGL/piongl.h \
    Interfaces/PlateauDuJeu/glwidget.h \
    Interfaces/Menus/menu_accueil.h \
    Interfaces/ObjetsGL/casegl.h \
    Interfaces/Panels/panel_creationjrs.h \
    Interfaces/Panels/panel_horloge.h \
    Interfaces/Panels/panel_infosjrs.h \
    Interfaces/Panels/tab_fichejr.h \
    Noyau/plateau_du_jeu.h \
    Noyau/pion.h \
    Noyau/partie.h \
    Noyau/joueur.h \
    Noyau/de.h \
    Noyau/damier.h \
    Noyau/case.h \
    Interfaces/PlateauDuJeu/cadre_de.h \
    Interfaces/Panels/panel_de.h \
    Controleur/controleur.h \
    Interfaces/PlateauDuJeu/cadre_pos_pion.h \
    Interfaces/Menus/menu_pause.h

FORMS    += \
    Interfaces/fenetre_principale.ui \
    Interfaces/Panels/panel_creationjrs.ui \
    Interfaces/Panels/panel_horloge.ui \
    Interfaces/Panels/panel_infosjrs.ui \
    Interfaces/Panels/tab_fichejr.ui \
    Interfaces/Panels/panel_de.ui

RESOURCES += \
    mesRessources.qrc
