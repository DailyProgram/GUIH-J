#-------------------------------------------------
#
# Project created by QtCreator 2019-06-23T16:35:29
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIH-J
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        experimentform.cpp \
        generationform.cpp \
        gistograms.cpp \
        main.cpp \
        mainwindow.cpp \
        qcustomplot.cpp \
        src/Generation/Generator.cpp \
        src/Generation/GuiSuequenceFiatureReader.cpp \
        src/Generation/Sequences.cpp \
        src/Sorts/MakerGistograms.cpp \
        src/Sorts/ReaderSequncesFiles.cpp \
        src/Sorts/Sort.cpp

HEADERS += \
        experimentform.h \
        generationform.h \
        gistograms.h \
        mainwindow.h \
        qcustomplot.h \
        src/Generation/Generator.h \
        src/Generation/GuiSuequenceFeatureReader.h \
        src/Generation/InterfaceSequences.h \
        src/Sorts/MakerGistograms.h \
        src/Sorts/ReaderSequncesFiles.h \
        src/Sorts/Sort.h \
        ui_mainwindow.h

FORMS += \
        experimentform.ui \
        generationform.ui \
        gistograms.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
