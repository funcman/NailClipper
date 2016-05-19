QT          +=          \
    core                \
    gui                 \
    widgets

TARGET      =           \
    NailClipper

TEMPLATE    =           \
    app

HEADERS     +=          \
    ncMainWindow.h      \
    ncOpenGLWidget.h

SOURCES     +=          \
    main.cpp            \
    ncMainWindow.cpp    \
    ncOpenGLWidget.cpp

FORMS       +=          \
    ncMainWindow.ui

RESOURCES +=            \
    resource.qrc

CONFIG      +=          \
    mobility

MOBILITY =
