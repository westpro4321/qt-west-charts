SOURCES += \
    testseries.cpp \
    main.cpp

HEADERS += \
    testseries.h

INCLUDEPATH += ../../src
DEPENDPATH += ../../src

LIBS+=  -L../../plugins -lQoc

QT += testlib
