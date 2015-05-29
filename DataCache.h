/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
#ifndef DATACACHE_H
#define DATACACHE_H

#include <qstring.h>


class DataCache
{
public:
    DataCache(int id, QString name, double lat, double lon);
    bool isFound() const;
    void setIsFound(bool isFound);

    bool isIgnore() const;
    void setIsIgnore(bool isIgnore);

    QString getName() const;
    double getLat() const;
    double getLon() const;

private:
    int m_id;
    QString m_name;
    double m_lat;
    double m_lon;
    bool m_isFound;
    bool m_isIgnore;
};

#endif // DATACACHE_H
