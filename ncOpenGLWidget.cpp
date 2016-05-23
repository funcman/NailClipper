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
    gfx_->resize(w, h);
}

void ncOpenGLWidget::paintGL() {
    gfx_->beginScene();
    gfx_->clear(RGBA(128,128,128,255));
    for (int i=0; i<128; i+=2) {
        gfx_->renderQuad(new ncQuad(i,      i,      this->width()-2*i,      this->height()-2*i,     RGBA(0,0,0,255)));
        gfx_->renderQuad(new ncQuad(i+1,    i+1,    this->width()-2*(i+1),  this->height()-2*(i+1), RGBA(255,0,0,255)));
    }
    gfx_->endScene();
}
