TEMPLATE = lib
CONFIG += qt plugin
QT += quick

TARGET = QocQuickPlugin

HEADERS += \
    qoc_quick_abstract_chart.h \
    qoc_quick_plugin.h \
    qoc_quick_view.h \
    qoc_quick_global.h \
    qoc_quick_bar_chart.h \
    qoc_quick_data_series.h \
    qoc_quick_data_item.h

SOURCES += \
    qoc_quick_abstract_chart.cpp \
    qoc_quick_plugin.cpp \
    qoc_quick_view.cpp \
    qoc_quick_bar_chart.cpp \
    qoc_quick_data_series.cpp \
    qoc_quick_data_item.cpp

INCLUDEPATH += ../src
DEPENDPATH += ../src

LIBS+=  -L../plugins -lQoc

DEFINES += QOC_QUICK_LIBRARY

DESTDIR = ../plugins

#OTHER_FILES = standalone/qmldir
