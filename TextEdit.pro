QT       += core gui sql charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

TARGET = TextEdit
DESTDIR += bin

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    boxtitle.cpp \
    db.cpp \
    dbmanager.cpp \
    log.cpp \
    main.cpp \
    mainwindow.cpp \
    newpage.cpp \
    showbody.cpp

HEADERS += \
    boxtitle.h \
    db.h \
    dbmanager.h \
    log.h \
    mainwindow.h \
    newpage.h \
    showbody.h

FORMS += \
    boxtitle.ui \
    mainwindow.ui \
    newpage.ui \
    showbody.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
