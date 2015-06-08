/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
#include <QGuiApplication>

#include "UiCache.h"
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QtQml>
#include "cacheFactory.h"
#include "QQuickWindow"

#include "controller.h"

int main(int argc, char *argv[])
{


    // geoUnit gu;

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;
    qmlRegisterType<UiCache>("MyModules", 1, 1, "CppCache");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    //-------setting up program state-machine ------------------
    Controller myController(engine);


    //---------------generate caches-----------
    CacheFactory factory(engine);
    factory.doGenerateUiCaches();





    /*
        QObjectList const*const oList= &engine.rootObjects()[0]->children();
        //&engine.children().append<QObject>(*o);
        for(int i= 0; i < oList->size();i++){
        qDebug() << (*oList)[i]->objectName();
    }
    */

    return app.exec();


}
