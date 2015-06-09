/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
#include "controller.h"


Controller::Controller(QQmlApplicationEngine &engine):pRootObj(engine.rootObjects()[0]){
    pMachine = new QStateMachine(&engine);

    pMainMenuState = new QState();         //main menu
    pGeoHuntState = new QState();





    pMachine->setObjectName("stateMachineObject");
    pClicker = pRootObj->findChild<QObject*>("stateSwitchClicker");
    pMainMenu = pRootObj->findChild<QObject*>("mainMenuObject");
    pMainMenuGrid = pMainMenu->findChild<QObject*>("gridObject");


    pGeoHuntObject= pRootObj->findChild<QObject*>("cacheHuntObject");

    pBackButtonObject = pRootObj->findChild<QObject*>("backButtonObject");


    //main menu properties
    pMainMenuState->assignProperty(pMainMenu, "z", 1);
    pMainMenuState->assignProperty(pMainMenu, "visible", true);
    pMainMenuState->assignProperty(pGeoHuntObject, "visible", false);
    pMainMenuState->assignProperty(pGeoHuntObject, "z", 0);
    pMainMenuState->assignProperty(pBackButtonObject, "visible", false);
    pMainMenuState->assignProperty(pBackButtonObject, "z", 0);


    //geo hunt properties
    pGeoHuntState->assignProperty(pMainMenu, "z", 0);
    pGeoHuntState->assignProperty(pMainMenu, "visible", false);
    pGeoHuntState->assignProperty(pGeoHuntObject, "visible", true);
    pGeoHuntState->assignProperty(pGeoHuntObject, "z", 1);
    pGeoHuntState->assignProperty(pBackButtonObject, "visible", true);
    pGeoHuntState->assignProperty(pBackButtonObject, "z", 1);


    //transitions
    pMainMenuState->addTransition(pMainMenuGrid->findChild<QObject*>("ghButton") , SIGNAL(clicked()), pGeoHuntState);
    pGeoHuntState->addTransition(pBackButtonObject, SIGNAL(click()), pMainMenuState);


    //init and start state machine

    pMachine->addState(pMainMenuState);
    pMachine->addState(pGeoHuntState);
    pMachine->setInitialState(pMainMenuState);
    pMachine->start();


}
