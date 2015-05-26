#include "controller.h"


Controller::Controller(QQmlApplicationEngine &engine):rootObj(engine.rootObjects()[0]){
    machine = new QStateMachine(&engine);
    geoHuntState = new QState;
    mainMenuState = new QState;
    machine->setObjectName("stateMachineObject");
    pClicker = rootObj->findChild<QObject*>("stateSwitchClicker");
    pGeoHuntObject= rootObj->findChild<QObject*>("cacheHuntObject");

    pBackButtonObject = rootObj->findChild<QObject*>("backButtonObject");
//default properties

    geoHuntState->assignProperty(pGeoHuntObject, "visible", true);
    mainMenuState->assignProperty(pGeoHuntObject, "visible", false);
    mainMenuState->assignProperty(pBackButtonObject, "visible", false);
    geoHuntState->assignProperty(pBackButtonObject, "visible", true);

    mainMenuState->addTransition(pClicker, SIGNAL(switchState()), geoHuntState);
    geoHuntState->addTransition(pBackButtonObject, SIGNAL(click()), mainMenuState);

    machine->addState(mainMenuState);
    machine->addState(geoHuntState);
    machine->setInitialState(mainMenuState);
    machine->start();


}
