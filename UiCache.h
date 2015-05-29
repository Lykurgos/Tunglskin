/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/

#ifndef UiCACHE_H
#define UiCACHE_H

#include <QQuickItem>
#include <QGeoCoordinate>

class UiCache : public QQuickItem
{
    Q_OBJECT
public:
    UiCache(QQuickItem *parent);
    UiCache();



    void setDistance(double co);
    double getDistance();
    void setAngle(double uc);
    double getAngle();

    Q_PROPERTY(double distance READ getDistance WRITE setDistance NOTIFY distanceChanged);
    Q_PROPERTY(double angle READ getAngle WRITE setAngle NOTIFY angleChanged);
    Q_PROPERTY(QString cacheName READ getName WRITE setName NOTIFY nameChanged);


    void setCoordinate(double lat, double longi);

    void setName(QString name);
    QString getName();
    void setY();
    void getX();
    void getY();
    void setX();

signals:
    void distanceChanged();
    void angleChanged();
    void geoCentreXYChanged();
    void nameChanged();

public slots:
    void setUserCoordinate(QVariant uc);
private:
    QString m_name;
    void updatePos();
    double fixAngle(double angle);
    double m_distance, m_angle;
    QGeoCoordinate validCo(const QGeoCoordinate &coIn);

QGeoCoordinate m_coordinate, m_userCoordinate;


};

#endif // UiCACHE_H
