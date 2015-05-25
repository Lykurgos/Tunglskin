#ifndef GEOUNIT_H
#define GEOUNIT_H

#include <QObject>
#include <QQuickItem>

class geoUnit : public QObject
{
    Q_OBJECT
public:
    explicit geoUnit(QObject *parent = 0);
 Q_INVOKABLE QString gimmeText();

signals:

public slots:
};

#endif // GEOUNIT_H
