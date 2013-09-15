HEADERS += \
    barchartbenchmark.h

SOURCES += \
    barchartbenchmark.cpp \
    main.cpp

INCLUDEPATH += ../../src
DEPENDPATH += ../../src

LIBS+=  -L../../plugins -lQoc

QT += testlib widgets
