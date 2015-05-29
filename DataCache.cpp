/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
#include "DataCache.h"


DataCache::DataCache(int id, QString name, double lat, double lon){
    m_id = id;
    m_name = name;
    m_lat = lat;
    m_lon = lon;
    m_isFound = false;
    m_isIgnore = false;
}
bool DataCache::isFound() const
{
    return m_isFound;
}

void DataCache::setIsFound(bool isFound)
{
    m_isFound = isFound;
}
bool DataCache::isIgnore() const
{
    return m_isIgnore;
}

void DataCache::setIsIgnore(bool isIgnore)
{
    m_isIgnore = isIgnore;
}
double DataCache::getLon() const
{
    return m_lon;
}

QString DataCache::getName() const
{
    return m_name;
}


double DataCache::getLat() const
{
    return m_lat;
}




