QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    contentsDialog.cpp \
    keyReceiver.cpp \
    main.cpp \
    mainwindow.cpp \
    pageDialog.cpp \
    processManager.cpp

HEADERS += \
    contentsDialog.h \
    keyReceiver.h \
    mainwindow.h \
    pageDialog.h \
    processManager.h

FORMS += \
    contentsDialog.ui \
    mainwindow.ui \
    pageDialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
