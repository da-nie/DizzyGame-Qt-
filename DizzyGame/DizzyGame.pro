#-------------------------------------------------
#
# Project created by QtCreator 2022-04-21T14:43:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CFLAGS += -Wno-unused-parameter
QMAKE_CFLAGS -= -Wunused-parameter
QMAKE_CXXFLAGS += -Wno-unused-parameter
QMAKE_CXXFLAGS -= -Wunused-parameter
QMAKE_CXXFLAGS_WARN_ON += -Wno-unused-parameter
QMAKE_CXXFLAGS_WARN_ON -= -Wunused-parameter
QMAKE_CXXFLAGS_WARN_OFF += -Wunused-parameter
QMAKE_CXXFLAGS_WARN_OFF -= -Wno-unused-parameter
QMAKE_CXXFLAGS+= -std=c++11

TARGET = DizzyGame
TEMPLATE = app


SOURCES += main.cpp\
        cmainwindow.cpp \
    cactionadditem.cpp \
    cactionaddlife.cpp \
    cactionaddscore.cpp \
    cactionchangeanimationmode.cpp \
    cactionchangedescription.cpp \
    cactionchangedescriptionglobal.cpp \
    cactionchangename.cpp \
    cactionchangenameglobal.cpp \
    cactionchangeposition.cpp \
    cactioncopyposition.cpp \
    cactioncopypositionoffset.cpp \
    cactionenergyupdate.cpp \
    cactionmessage.cpp \
    cactionmove.cpp \
    cactionpickup.cpp \
    cactionsetanimationstep.cpp \
    cactionsetenabled.cpp \
    cactionsingle.cpp \
    cautomath.cpp \
    cconditionalofdizzyintersection.cpp \
    cconditionalofintersection.cpp \
    cconditionalofnotdizzyintersection.cpp \
    cconditionalofpickup.cpp \
    cconditionaloftimer.cpp \
    cconditionalofuse.cpp \
    cdizzy.cpp \
    cfontprinter.cpp \
    cgame.cpp \
    cgamestate.cpp \
    clexeme.cpp \
    clexicalanalyzer.cpp \
    cpart.cpp \
    craiifilein.cpp \
    craiifileout.cpp \
    csprite.cpp \
    csyntaxanalyzer.cpp \
    ctile.cpp \
    ctilessequence.cpp \
    cvideo_software.cpp \
    iaction.cpp \
    iconditionalexpression.cpp \
    ipart.cpp \
    ivideo.cpp \
    system.cpp \
    tga.cpp

HEADERS  += cmainwindow.h \
    cactionadditem.h \
    cactionaddlife.h \
    cactionaddscore.h \
    cactionchangeanimationmode.h \
    cactionchangedescription.h \
    cactionchangedescriptionglobal.h \
    cactionchangename.h \
    cactionchangenameglobal.h \
    cactionchangeposition.h \
    cactioncopyposition.h \
    cactioncopypositionoffset.h \
    cactionenergyupdate.h \
    cactionmessage.h \
    cactionmove.h \
    cactionpickup.h \
    cactionsetanimationstep.h \
    cactionsetenabled.h \
    cactionsingle.h \
    cautomath.h \
    cconditionalofdizzyintersection.h \
    cconditionalofintersection.h \
    cconditionalofnotdizzyintersection.h \
    cconditionalofpickup.h \
    cconditionaloftimer.h \
    cconditionalofuse.h \
    cdizzy.h \
    cfontprinter.h \
    cgame.h \
    cgamestate.h \
    clexeme.h \
    clexicalanalyzer.h \
    cpart.h \
    craiifilein.h \
    craiifileout.h \
    csprite.h \
    csyntaxanalyzer.h \
    ctile.h \
    ctilessequence.h \
    cvideo_software.h \
    iaction.h \
    iconditionalexpression.h \
    ipart.h \
    ivideo.h \
    system.h \
    tga.h

FORMS    += cmainwindow.ui

DISTFILES += \
    license.txt
