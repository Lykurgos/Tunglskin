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

  signals:

    void distanceChanged();
    void angleChanged();
    void geoCentreXYChanged();

public slots:
    void setUserCoordinate(QVariant uc);
private:
    void updatePos();
    double fixAngle(double angle);
    double m_distance, m_angle;
    QGeoCoordinate validCo(const QGeoCoordinate &coIn);

QGeoCoordinate m_coordinate, m_userCoordinate;


};

#endif // UiCACHE_H
