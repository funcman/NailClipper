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
    ncVector.h          \
    ncMatrix.h          \
    ncVertex.h          \
    ncTriple.h          \
    ncQuad.h            \
    ncGraphics.h        \
    ncTexture.h

SOURCES     +=          \
    main.cpp            \
    ncMainWindow.cpp    \
    ncOpenGLWidget.cpp  \
    ncVector.cpp        \
    ncMatrix.cpp        \
    ncVertex.cpp        \
    ncTriple.cpp        \
    ncQuad.cpp          \
    ncGraphics.cpp      \
    ncTexture.cpp

FORMS       +=          \
    ncMainWindow.ui

RESOURCES   +=          \
    shaders.qrc         \
    images.qrc

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
