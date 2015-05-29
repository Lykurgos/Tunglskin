/*
Author: Fredrik Bakke, bakkefredrik@gmail.com
Date: 8.6-2015
License: GNU GENERAL PUBLIC LICENSE Version 2, June 1991
*/
#include "UiCache.h"
UiCache::UiCache(QQuickItem* parent):m_coordinate(0.0,0.0),m_userCoordinate(0.0,0.0),QQuickItem(parent){
}

UiCache::UiCache():m_coordinate(0.0,0.0),m_userCoordinate(0.0,0.0){
}



//property binding
double UiCache::getDistance()
{
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
}

void UiCache::setCoordinate(double lat, double longi)
{
        m_coordinate.setLatitude(lat);
        m_coordinate.setLongitude(longi);
        updatePos();
}
void UiCache::setName(QString name){
    m_name = name;
    emit nameChanged();
}

QString UiCache::getName(){
    return m_name;
}
