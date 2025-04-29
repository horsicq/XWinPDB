INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

HEADERS += \
    $$PWD/xwinpdb.h \
    $$PWD/xwinpdb_def.h

SOURCES += \
    $$PWD/xwinpdb.cpp

win32 {
HEADERS += \
    $$PWD/msdia/cvConst.h \
    $$PWD/msdia/dia2.h \
    $$PWD/msdia/diaCreate.h \

SOURCES += \
    $$PWD/msdia/diaCreate.cpp \
}

DISTFILES += \
    $$PWD/LICENSE \
    $$PWD/README.md \
    $$PWD/xwinpdb.cmake

!contains(XCONFIG, xpe) {
    XCONFIG += xpe
    include($$PWD/../Formats/exec/xpe.pri)
}

INCLUDEPATH += $$PWD/msdia
DEPENDPATH += $$PWD/msdia
