#include "DataCache.h"


DataCache::DataCache(int id, QString name, double x, double y){
    m_id = id;
    m_name = name;
    m_x = x;
    m_y = y;
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


