#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QStateMachine>
#include <QQmlApplicationEngine>
class Controller
{
public:
    Controller(QQmlApplicationEngine &engine);


    private:
    QObject * rootObj;
    QObject * pClicker;
    QObject * pGeoHuntObject;
    QObject * pBackButtonObject;


    QState* mainMenuState;
    QState* geoHuntState;
    QStateMachine *machine;
};

#endif // CONTROLLER_H
