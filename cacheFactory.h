#ifndef CACHEFACTORY_H
#define CACHEFACTORY_H
#include "UiCache.h"

#include <QGeoCoordinate>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QtQml>
#include <vector>
#include "DataCache.h"

#include <QtSql/QtSql>

class CacheFactory
{
public:
    CacheFactory(QQmlApplicationEngine &engine);
public:
    void doGenerateUiCaches();
private:
    std::vector<DataCache> m_dataCacheVector;
    QQmlApplicationEngine *m_engine;

    void openDataBase();
    void closeDataBase();

    QSqlDatabase m_db;
};

#endif // CACHEFACTORY_H
