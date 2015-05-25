#include "controller.h"


Controller::Controller(QQmlApplicationEngine &engine):rootObj(engine.rootObjects()[0]),machine(rootObj){

    machine.setObjectName("stateMachineObject");

    rootObj = engine.rootObjects()[0];
    pClicker = rootObj->findChild<QObject*>("stateSwitchClicker");




    s1.addTransition(pClicker, SIGNAL(switchState()), &s2);
    s2.addTransition(pClicker, SIGNAL(switchState()), &s1);




    machine.addState(&s1);
    machine.addState(&s2);
    machine.setInitialState(&s1);
    machine.start();

}
bool Controller::handleStateChange(){

}
