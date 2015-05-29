/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/

#ifndef CACHEFACTORY_H
#define CACHEFACTORY_H
#include "UiCache.h"
#include <algorithm>
#include <QGeoCoordinate>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QtQml>
#include <vector>
#include "DataCache.h"
#include "GpxFile.h"

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
    GpxFile m_gpxFile;
};

#endif // CACHEFACTORY_H
