#include "ncMainWindow.h"
#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setDepthBufferSize(16);
    format.setStencilBufferSize(8);
    format.setVersion(3, 3);
    QSurfaceFormat::setDefaultFormat(format);

    ncMainWindow w;
    w.show();

    return a.exec();
}
