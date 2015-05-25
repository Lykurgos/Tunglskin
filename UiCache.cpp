#include "UiCache.h"
UiCache::UiCache(QQuickItem* parent):m_coordinate(59.000005,09.0),m_userCoordinate(0.0,0.0),QQuickItem(parent){
}

UiCache::UiCache():m_coordinate(59.000005,09.0),m_userCoordinate(0.0,0.0){
}


//property binding
double UiCache::getDistance()
{
qDebug() << QString("read dist");
     return m_distance;
}

//property binding
void UiCache::setDistance(double dist)
{
    if (m_distance!= dist)
    {
        m_distance= dist;
        emit distanceChanged();
    }
}
//property binding
double UiCache::getAngle()
{
     return m_angle;
}

//property binding
void UiCache::setAngle(double angle)
{
    if (m_angle!= angle)
    {
        m_angle= angle;
        emit angleChanged();
    }
}


QGeoCoordinate UiCache::validCo(const QGeoCoordinate &coIn){

        if(coIn.isValid()){
            return coIn;
        }else{
            return QGeoCoordinate(0.0, 0.0);
        }
}
double UiCache::fixAngle(double angle){
    if(angle < 0){
        return angle+360;
    }else if (angle >= 360){
        return angle-360;
    }else{
        return angle;
    }

}

 void UiCache::updatePos(){
     setDistance(m_coordinate.distanceTo(validCo(m_userCoordinate)));
     setAngle(fixAngle((m_userCoordinate.azimuthTo(m_coordinate)-90) * (-1)));
 }

//SLOT
void UiCache::setUserCoordinate(QVariant uc)
{

    if (m_userCoordinate!= uc.value<QGeoCoordinate>())
    {
        m_userCoordinate=  uc.value<QGeoCoordinate>();
     }
updatePos();
//     qDebug() << "new uco set, lat: " << m_userCoordinate.latitude() << " long: " << m_userCoordinate.longitude() << "\n";
}

