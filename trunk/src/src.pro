
QT = core gui widgets

TEMPLATE = app

HEADERS = qoc_global.h \
    qoc_data_series.h \
    qoc_abstract_chart_item.h \
    qoc_legend.h \
    qoc_pie_sector.h \
    qoc_pie_chart.h \
    qoc_data_series_owner.h \
    testwidget.h \
    mainwindow.h \
    qoc_abstract_chart.h

SOURCES += \
    main.cpp \
    qoc_abstract_chart_item.cpp \
    qoc_legend.cpp \
    qoc_pie_sector.cpp \
    qoc_pie_chart.cpp \
    testwidget.cpp \
    mainwindow.cpp \
    qoc_abstract_chart.cpp

FORMS += \
    mainwindow.ui
