QT       += core gui
QT += sql
RC_ICONS = Header.ico
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aboutpage.cpp \
    dbaccess.cpp \
    favorites.cpp \
    fusion.cpp \
    fusionpage.cpp \
    helppage.cpp \
    main.cpp \
    infowindow.cpp \
    persona.cpp \
    settings.cpp

HEADERS += \
    aboutpage.h \
    dbaccess.h \
    favorites.h \
    fusion.h \
    fusionpage.h \
    helppage.h \
    infowindow.h \
    persona.h \
    settings.h

FORMS += \
    aboutpage.ui \
    favorites.ui \
    fusionpage.ui \
    helppage.ui \
    infowindow.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
