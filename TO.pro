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
    conteofiltrado.cpp \
    csvparser.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    puntob.cpp

HEADERS += \
    AVLTree.h \
    Registro.h \
    VectorPlus.h \
    conteofiltrado.h \
    csvparser.h \
    mainpage.h \
    mainwindow.h \
    pacientedata.h \
    puntob.h

FORMS += \
    mainpage.ui \
    mainwindow.ui \
    puntob.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
