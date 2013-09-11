
QT = core gui widgets quick

TEMPLATE = app

HEADERS = qoc_global.h \
    qoc_abstract_chart_item.h \
    qoc_legend.h \
    qoc_pie_sector.h \
    qoc_pie_chart.h \
    testwidget.h \
    mainwindow.h \
    qoc_abstract_chart.h \
    qoc_data_series.h \
    qoc_data_item.h

SOURCES += \
    main.cpp \
    qoc_abstract_chart_item.cpp \
    qoc_legend.cpp \
    qoc_pie_sector.cpp \
    qoc_pie_chart.cpp \
    testwidget.cpp \
    mainwindow.cpp \
    qoc_abstract_chart.cpp \
    qoc_data_series.cpp \
    qoc_data_item.cpp

FORMS += \
    mainwindow.ui

DEFINES += QOC_LIBRARY
