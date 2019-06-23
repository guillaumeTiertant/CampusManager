QT += core
QT -= gui

CONFIG += c++17

TARGET = CampusManager
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += cpp/main.cpp \
    cpp/campus.cpp \
    cpp/externalTeacher.cpp \
    cpp/fullCampusException.cpp \
    cpp/helper.cpp \
    cpp/internalTeacher.cpp \
    cpp/student.cpp \
    cpp/teacher.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    cpp/campus.h \
    cpp/externalTeacher.h \
    cpp/fullCampusException.h \
    cpp/helper.h \
    cpp/internalTeacher.h \
    cpp/student.h \
    cpp/teacher.h \
    cpp/trycode.h

win32
{
INCLUDEPATH += "C:\Program Files (x86)\boost_1_70_0\boost_1_70_0"
}

unix
{
INCLUDEPATH += /home/guillaume/Documents/Pro/Qt/Utilitaires/boost_1_66_0
}
