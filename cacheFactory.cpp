#include "cacheFactory.h"

CacheFactory::CacheFactory(QQmlApplicationEngine &engine): m_engine(&engine)
{

}


void CacheFactory::doGenerateUiCaches(int count){


    QObject * rootObj = m_engine->rootObjects()[0];

    QObject * cacheHuntObj = rootObj->findChild<QObject*>("cacheHuntObject");

    QQuickItem * p_meObject = qobject_cast<QQuickItem*>(cacheHuntObj->findChild<QObject*>("meObject"));
    p_meObject->setProperty("coordinate.latitude", 57.0);
    p_meObject->setProperty("coordinate.latitude", 09.0);

    QQmlComponent *c = new QQmlComponent(m_engine, QUrl("qrc:/Cache.qml"), cacheHuntObj);

    for(int i = 0; i < count; i++){

        QObject *o = c->create();
        QQuickItem *cacheItem = qobject_cast<QQuickItem*>(o);
        UiCache* p_cacheCache = qobject_cast<UiCache*>(o);

        o->setObjectName(QString("CacheObj")+(i+65));

        QQuickItem * p_geoArea = qobject_cast<QQuickItem*>(cacheHuntObj->findChild<QObject*>("geoArea"));

        cacheItem->setParentItem(p_geoArea);
        o->setParent(cacheHuntObj);

        //set user position initialy

        QObject::connect(p_meObject, SIGNAL(userCoordinateUpdate(QVariant)),
                             p_cacheCache, SLOT(setUserCoordinate(QVariant)));
    }

}
