#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QStateMachine>
#include <QQmlApplicationEngine>
class Controller
{
public:
    Controller(QQmlApplicationEngine &engine);

    Q_PROPERTY(bool geoHunt READ getGeoHunt WRITE setGeoHunt NOTIFY geoHuntChanged);


    bool handleStateChange();

    private:
       QObject * rootObj;
    QObject * pClicker;
    QState s1;
    QState s2;

    QStateMachine machine;
};

#endif // CONTROLLER_H
