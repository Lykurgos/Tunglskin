TEMPLATE = app

QT += qml quick positioning core gui widgets sql

SOURCES += main.cpp \
    cacheFactory.cpp \
    UiCache.cpp \
    controller.cpp

RESOURCES += qml.qrc \
    images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    ../../../../usr/share/icons/default/index.theme \
    ../../../../usr/share/icons/cab_view.png \
    XmlLoader.qml

HEADERS += \
    cacheFactory.h \
    UiCache.h \
    controller.h
