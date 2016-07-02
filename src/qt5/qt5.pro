#-------------------------------------------------
#
# Project created by QtCreator 2015-11-07T20:17:01
#
#-------------------------------------------------

QT += network core gui
# QT += opengl
#QT       +=
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = Analyst
DESTDIR = ../../bin

DEPENDPATH += . ../model
win32 {
  DEPENDPATH += ../../rcsc
}

INCLUDEPATH += . ..  ../.. ../model
win32 {
  INCLUDEPATH +=  ../../boost
}
unix {
  INCLUDEPATH += ${HOME}/local/include
  INCLUDEPATH += /opt/local/include
}
macx {
  INCLUDEPATH += /opt/local/include
}

LIBS += -L../../lib
LIBS += -lanalyst_model
win32 {
  LIBS += -lrcsc ../../zlib/zlib1.dll -lwsock32
}
unix {
  LIBS += -L${HOME}/local/lib
  LIBS += -lrcsc_agent -lrcsc_time -lrcsc_ann -lrcsc_param -lrcsc_gz -lrcsc_rcg -lrcsc_net -lrcsc_geom -lz
}

DEFINES += HAVE_LIBRCSC_GZ
win32 {
  DEFINES += HAVE_WINDOWS_H NO_TIMER
#  DEFINES += USE_GLWIDGET
}
unix {
  DEFINES += HAVE_NETINET_IN_H
}
DEFINES += PACKAGE_NAME="\\\"Analyst\\\"" VERSION="\\\"1.0.0\\\""

CONFIG += qt warn_on release
win32 {
  CONFIG += windows
}

#QMAKE_LFLAGS_DEBUG += -static
#QMAKE_LFLAGS_DEBUG += -pg
#QMAKE_CFLAGS_DEBUG += -pg -static -DQABSTRACTSOCKET_DEBUG
QMAKE_CXXFLAGS += -static
#QMAKE_CXXFLAGS_DEBUG += -pg -static -DQABSTRACTSOCKET_DEBUG




SOURCES += main.cpp\
        mainwindow.cpp \
    tec_data.cpp \
    log.cpp

HEADERS  += mainwindow.h \
    tec_data.h \
    log.h \
    basedata.h

FORMS    += mainwindow.ui
