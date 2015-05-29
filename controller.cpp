/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
#include "controller.h"


Controller::Controller(QQmlApplicationEngine &engine):rootObj(engine.rootObjects()[0]){
    machine = new QStateMachine(&engine);
    geoHuntState = new QState;
    mainMenuState = new QState;

    machine->setObjectName("stateMachineObject");
    pClicker = rootObj->findChild<QObject*>("stateSwitchClicker");
    pMainMenu = rootObj->findChild<QObject*>("mainMenuObject");
    pMainMenuGrid = pMainMenu->findChild<QObject*>("gridObject");


    pGeoHuntObject= rootObj->findChild<QObject*>("cacheHuntObject");

    pBackButtonObject = rootObj->findChild<QObject*>("backButtonObject");
//default properties


    mainMenuState->assignProperty(pGeoHuntObject, "visible", false);
    mainMenuState->assignProperty(pBackButtonObject, "visible", false);

    geoHuntState->assignProperty(pBackButtonObject, "visible", true);
    geoHuntState->assignProperty(pGeoHuntObject, "visible", true);

    geoHuntState->assignProperty(pGeoHuntObject, "z", 1);

    mainMenuState->addTransition(pMainMenuGrid->findChild<QObject*>("ghButton") , SIGNAL(clicked()), geoHuntState);
    geoHuntState->addTransition(pBackButtonObject, SIGNAL(click()), mainMenuState);

    machine->addState(mainMenuState);
    machine->addState(geoHuntState);
    machine->setInitialState(mainMenuState);
    machine->start();


}
