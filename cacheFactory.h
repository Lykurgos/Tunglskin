#ifndef CACHEFACTORY_H
#define CACHEFACTORY_H
#include "UiCache.h"

#include <QGeoCoordinate>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QtQml>


class CacheFactory
{
public:
    CacheFactory(QQmlApplicationEngine &engine);
public:
    void doGenerateUiCaches(int count);
private:
    QQmlApplicationEngine *m_engine;
};

#endif // CACHEFACTORY_H
