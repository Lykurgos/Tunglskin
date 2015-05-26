#ifndef DATACACHE_H
#define DATACACHE_H

#include <qstring.h>


class DataCache
{
public:
    DataCache(int id, QString name, double x, double y);
    bool isFound() const;
    void setIsFound(bool isFound);

    bool isIgnore() const;
    void setIsIgnore(bool isIgnore);

private:
    int m_id;
    QString m_name;
    double m_x;
    double m_y;
    bool m_isFound;
    bool m_isIgnore;
};

#endif // DATACACHE_H
