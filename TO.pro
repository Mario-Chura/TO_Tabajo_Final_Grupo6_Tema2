QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AVLTree.cpp \
    Registro.cpp \
    VectorPlus.cpp \
    estadistica1.cpp \
    estadistica2.cpp \
    estadistica3.cpp \
    estadistica4.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    principal.cpp

HEADERS += \
    AVLTree.h \
    DataHolder.h \
    Registro.h \
    VectorPlus.h \
    estadistica1.h \
    estadistica2.h \
    estadistica3.h \
    estadistica4.h \
    mainpage.h \
    mainwindow.h \
    principal.h

FORMS += \
    estadistica1.ui \
    estadistica2.ui \
    estadistica3.ui \
    estadistica4.ui \
    mainpage.ui \
    mainwindow.ui \
    principal.ui

QT += widgets
QT += printsupport



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
