/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/

#include "cacheFactory.h"

CacheFactory::CacheFactory(QQmlApplicationEngine &engine): m_engine(&engine)
{

}

void CacheFactory::openDataBase(){
    //add sqlite3 database
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("hunts.db3");


    m_db.open();
    if(!m_db.isOpen()){
        qDebug() << "WTF database not open";

    }else{
        qDebug() << "database open";

    }






    QSqlQuery createTableQuery("CREATE TABLE \"Caches\" (\"Id\" INTEGER PRIMARY KEY ,\"Name\" TEXT,\"Latitude\" DOUBLE NOT NULL  DEFAULT (0) ,\"Longitude\" DOUBLE NOT NULL  DEFAULT (0) , \"isFound\" BOOL NOT NULL  DEFAULT false, \"ignore\" bool NOT NULL  DEFAULT false, \"Hunt\" INTEGER DEFAULT 0)");
    createTableQuery.exec();

    //QSqlQuery addCacheQuery("INSERT INTO Caches(name, x,y) VALUES(\"Some cache\",23,34)");
    //addCacheQuery.exec();


    if(!m_db.transaction()){
        qDebug() << "transactions not supported";

    }
}
void CacheFactory::closeDataBase(){
    m_db.close();
}

void CacheFactory::doGenerateUiCaches(){


    QObject * rootObj = m_engine->rootObjects()[0];
    QObject * cacheHuntObj = rootObj->findChild<QObject*>("cacheHuntObject");
    QQuickItem * p_meObject = qobject_cast<QQuickItem*>(cacheHuntObj->findChild<QObject*>("meObject"));
    QQuickItem * p_geoArea = qobject_cast<QQuickItem*>(cacheHuntObj->findChild<QObject*>("geoArea"));


    QQmlComponent *c = new QQmlComponent(m_engine, QUrl("qrc:/Cache.qml"), cacheHuntObj);


    m_gpxFile.doParse(QString("caches.gpx"));
    std::vector<DataCache> cachesFromGpx= m_gpxFile.getCaches();

    for(int i = 0; i < cachesFromGpx.size(); ++i){

        QObject *o = c->create();
        QQuickItem *cacheItem = qobject_cast<QQuickItem*>(o);
        UiCache* p_cacheCache = qobject_cast<UiCache*>(o);

        o->setObjectName(QString("CacheName: ")+"cache-"+cachesFromGpx[i].getName());
        cacheItem->setParentItem(p_geoArea);
        o->setParent(cacheHuntObj);

        p_cacheCache->setCoordinate(cachesFromGpx[i].getLat(), cachesFromGpx[i].getLon());
        p_cacheCache->setName(cachesFromGpx[i].getName());


        QObject::connect(p_meObject, SIGNAL(userCoordinateUpdate(QVariant)),
                             p_cacheCache, SLOT(setUserCoordinate(QVariant)));

    }






/*
    openDataBase();


    QSqlQuery cacheQuery("SELECT * from Caches");
    cacheQuery.exec();

    qDebug() << QString("last error: ") << cacheQuery.lastError().text();

    QObject * rootObj = m_engine->rootObjects()[0];
    QObject * cacheHuntObj = rootObj->findChild<QObject*>("cacheHuntObject");
    QQuickItem * p_meObject = qobject_cast<QQuickItem*>(cacheHuntObj->findChild<QObject*>("meObject"));
    QQuickItem * p_geoArea = qobject_cast<QQuickItem*>(cacheHuntObj->findChild<QObject*>("geoArea"));


    QQmlComponent *c = new QQmlComponent(m_engine, QUrl("qrc:/Cache.qml"), cacheHuntObj);

    int fieldNoId = cacheQuery.record().indexOf("Id");
    int fieldNoLat = cacheQuery.record().indexOf("Latitude");
    int fieldNoLong= cacheQuery.record().indexOf("Longitude");
    int fieldNoName= cacheQuery.record().indexOf("Name");


    while(cacheQuery.next()){
        QObject *o = c->create();
        QQuickItem *cacheItem = qobject_cast<QQuickItem*>(o);
        UiCache* p_cacheCache = qobject_cast<UiCache*>(o);

        o->setObjectName(QString("CacheName: ")+cacheQuery.value(fieldNoName).toString());
        cacheItem->setParentItem(p_geoArea);
        o->setParent(cacheHuntObj);

        p_cacheCache->setCoordinate(cacheQuery.value(fieldNoLat).toDouble(), cacheQuery.value(fieldNoLong).toDouble());
        p_cacheCache->setName(cacheQuery.value(fieldNoName).toString());


        QObject::connect(p_meObject, SIGNAL(userCoordinateUpdate(QVariant)),
                             p_cacheCache, SLOT(setUserCoordinate(QVariant)));
    }
    closeDataBase();
*/
}
