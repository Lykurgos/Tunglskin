TEMPLATE = app

QT += qml quick positioning core gui widgets sql

SOURCES += main.cpp \
    cacheFactory.cpp \
    UiCache.cpp \
    controller.cpp \
    DataCache.cpp \
    GpxFile.cpp \
    geohuntsmodel.cpp \
    SqlQueryModel.cpp

RESOURCES += qml.qrc \
    images.qrc

CONFIG += C++11

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

DISTFILES += \
    ../../../../usr/share/icons/default/index.theme \
    ../../../../usr/share/icons/cab_view.png \
    MainMenu.qml

HEADERS += \
    cacheFactory.h \
    UiCache.h \
    controller.h \
    DataCache.h \
    GpxFile.h \
    geohuntsmodel.h \
    SqlQueryModel.h
