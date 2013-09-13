TEMPLATE = lib
CONFIG += qt plugin
QT += quick qml widgets

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

LIBS+=  -L../src -lQoc

DEFINES += QOC_QUICK_LIBRARY
