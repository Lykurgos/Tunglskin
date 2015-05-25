#include "geounit.h"

geoUnit::geoUnit(QObject *parent) : QObject(parent)
{



}

Q_INVOKABLE QString geoUnit::gimmeText() {
            return QString("new text");
}
