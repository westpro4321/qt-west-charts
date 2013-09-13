
QT = core gui widgets

TEMPLATE = lib
#

HEADERS = qoc_global.h \
    qoc_abstract_chart_item.h \
    qoc_legend.h \
#    qoc_pie_sector.h \
#    qoc_pie_chart.h \
    qoc_abstract_chart.h \
    qoc_data_series.h \
    qoc_data_item.h \
    qoc_signal_mapper.h \
    qoc_adaptor_model.h \
    qoc_view_widget.h \
    qoc_bar_chart.h \
    qoc_axis.h \
    qoc_bar_item.h \
    qoc_abstract_value_item.h

SOURCES += \
#    main.cpp \
    qoc_abstract_chart_item.cpp \
    qoc_legend.cpp \
#    qoc_pie_sector.cpp \
#    qoc_pie_chart.cpp \
    qoc_abstract_chart.cpp \
    qoc_data_series.cpp \
    qoc_data_item.cpp \
    qoc_signal_mapper.cpp \
    qoc_adaptor_model.cpp \
    qoc_view_widget.cpp \
    qoc_bar_chart.cpp \
    qoc_axis.cpp \
    qoc_bar_item.cpp \
    qoc_abstract_value_item.cpp

DEFINES += QOC_LIBRARY QT_NO_DEBUG_OUTPUT

TARGET = Qoc
