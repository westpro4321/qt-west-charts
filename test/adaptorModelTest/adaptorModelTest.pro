INCLUDEPATH += ../../src
DEPENDPATH += ../../src

LIBS+=  -L../../plugins -lQoc

QT += testlib

HEADERS += \
    testadaptormodel.h

SOURCES += \
    testadaptormodel.cpp \
    main.cpp
