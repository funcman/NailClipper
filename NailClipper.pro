QT          +=          \
    core                \
    gui                 \
    widgets

TARGET      =           \
    NailClipper

TEMPLATE    =           \
    app

HEADERS     +=          \
    ncMainWindow.h

SOURCES     +=          \
    main.cpp            \
    ncMainWindow.cpp


FORMS       +=          \
    ncMainWindow.ui

CONFIG      +=          \
    mobility

MOBILITY =
