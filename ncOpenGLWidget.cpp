#include "ncOpenGLWidget.h"
#include "ncGraphics.h"

ncOpenGLWidget::ncOpenGLWidget(QWidget* parent)
:   QOpenGLWidget(parent)
,   gfx_(0) {
}

ncOpenGLWidget::~ncOpenGLWidget() {
    this->makeCurrent();
    delete gfx_;
    this->doneCurrent();
}

void ncOpenGLWidget::initializeGL() {
    gfx_ = new ncGraphics();
}

void ncOpenGLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, qMax(h, 1));
}

void ncOpenGLWidget::paintGL() {
    gfx_->beginScene();
    gfx_->clear(RGBA(128,128,128,255));
    gfx_->renderQuad(new ncQuad(-0.5f, -0.5f, 1.f, 1.f, RGBA(255,0,0,255)));
    gfx_->endScene();
}
