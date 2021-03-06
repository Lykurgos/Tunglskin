/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/


#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QStateMachine>
#include <QQmlApplicationEngine>
 class Controller
{
public:
    Controller(QQmlApplicationEngine &engine);
    private:
    QObject * pRootObj;
    QObject * pClicker;
    QObject * pGeoHuntObject;
    QObject * pBackButtonObject;
    QObject * pMainMenu;
    QObject * pMainMenuGrid;

    QState* pMainMenuState;
    QState* pGeoHuntState;
    QStateMachine * pMachine;
};

#endif // CONTROLLER_H
