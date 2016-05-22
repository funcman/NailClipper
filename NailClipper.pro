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
    ncOpenGLWidget.h    \
    ncMatrix.h          \
    ncVertex.h          \
    ncTriple.h          \
    ncQuad.h            \
    ncGraphics.h

SOURCES     +=          \
    main.cpp            \
    ncMainWindow.cpp    \
    ncOpenGLWidget.cpp  \
    ncMatrix.cpp        \
    ncVertex.cpp        \
    ncTriple.cpp        \
    ncQuad.cpp          \
    ncGraphics.cpp

FORMS       +=          \
    ncMainWindow.ui

RESOURCES   +=          \
    shaders.qrc

win32 {
    LIBS    +=          \
        -lopengl32
}

macx {
}

unix {
}

ios {
}

android {
}
