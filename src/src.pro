
QT = core gui widgets

TEMPLATE = app

HEADERS = qoc_global.h \
    qoc_data_series.h \
    qoc_abstract_chart.h \
    qoc_abstract_chart_item.h \
    qoc_legend.h \
    qoc_pie_sector.h

SOURCES += \
    main.cpp \
    qoc_abstract_chart.cpp \
    qoc_abstract_chart_item.cpp \
    qoc_legend.cpp \
    qoc_pie_sector.cpp
