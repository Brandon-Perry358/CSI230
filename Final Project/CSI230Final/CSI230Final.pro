QT += widgets network

TARGET = secureudpserver
TEMPLATE = app

SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS = mainwindow.ui

target.path = $$[QT_INSTALL_EXAMPLES]/network/secureudpserver
INSTALLS += target
