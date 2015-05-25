#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include "geounit.h"
#include "UiCache.h"
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QtQml>
//#include <QGeoPositionInfoSource>
#include "cacheFactory.h"
#include "QQuickWindow"

#include <QtSql/QtSql>
#include "controller.h"


int main(int argc, char *argv[])
{

    // geoUnit gu;

    //add sqlite3 database
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("hunts.db3");


    db.open();
    if(!db.isOpen()){
        qDebug() << "WTF database not open";

    }
    if(!db.transaction()){
        qDebug() << "transactions not supported";

    }

    QSqlQuery test;


    db.close(); // for close connection

    QGuiApplication app(argc, argv);






    QQmlApplicationEngine engine;
    qmlRegisterType<UiCache>("MyModules", 1, 1, "CppCache");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));






    //-------setting up program state-machine ------------------


    //Controller myController(engine);


    //---------------------------







    //---------------generate caches-----------
    CacheFactory factory(engine);
    factory.doGenerateUiCaches(1);
    //-------------------------------------




    /*
        QObjectList const*const oList= &engine.rootObjects()[0]->children();
        //&engine.children().append<QObject>(*o);
        for(int i= 0; i < oList->size();i++){
        qDebug() << (*oList)[i]->objectName();
    }
    */

    return app.exec();


}
