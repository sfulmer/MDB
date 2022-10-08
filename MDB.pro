QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MDBApp.cpp \
    MDBController.cpp \
    MDBMainPanel.cpp \
    MDBSettingsBaseURLsListPanel.cpp \
    MDBSettingsDialog.cpp \
    MDBSettingsModel.cpp \
    Observable.cpp \
    main.cpp \
    MDBMainWindow.cpp

HEADERS += \
    MDBApp.h \
    MDBController.h \
    MDBMainPanel.h \
    MDBMainWindow.h \
    MDBSettingsBaseURLsListPanel.h \
    MDBSettingsDialog.h \
    MDBSettingsModel.h \
    Observable.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
