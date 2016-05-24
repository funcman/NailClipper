#include "ncMainWindow.h"
#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char** argv) {
    QSurfaceFormat format;
#if defined(Q_OS_IOS) || defined(Q_OS_ANDROID)
    format.setRenderableType(QSurfaceFormat::OpenGLES);
    format.setVersion(3, 0);
#else
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(3, 3);
#endif
    format.setDepthBufferSize(16);
    format.setStencilBufferSize(8);
    QSurfaceFormat::setDefaultFormat(format);

    QApplication a(argc, argv);

    ncMainWindow w;
    w.show();

    return a.exec();
}
