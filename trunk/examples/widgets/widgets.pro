QT = core gui widgets

TEMPLATE = app

#HEADERS = testwidget.h \
#    mainwindow.h

#SOURCES = main.cpp \
#   testwidget.cpp \
#   mainwindow.cpp \


#FORMS += \
#    mainwindow.ui

INCLUDEPATH += ../../src
DEPENDPATH += ../../src

LIBS+=  -L../../src -lQoc

SOURCES += main.cpp
#HEADERS += ../../src/qoc_data_series.h
