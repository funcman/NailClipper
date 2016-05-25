#include "ncOpenGLWidget.h"
#include <QGuiApplication>
#include <QScreen>
#include "ncGraphics.h"
#include "ncTexture.h"

ncOpenGLWidget::ncOpenGLWidget(QWidget* parent)
:   QOpenGLWidget(parent)
,   gfx_(0)
,   tex_(0) {
}

ncOpenGLWidget::~ncOpenGLWidget() {
    delete tex_;
    this->makeCurrent();
    delete gfx_;
    this->doneCurrent();
}

void ncOpenGLWidget::initializeGL() {
    gfx_ = new ncGraphics();
    tex_ = new ncTexture(":/demo.jpg");
}

void ncOpenGLWidget::resizeGL(int, int) {
    gfx_->resize(this->pixelWidth(), this->pixelHeight());
}

void ncOpenGLWidget::paintGL() {
    gfx_->beginScene();
    gfx_->clear(RGBA(128,128,128,255));
    int i;
    for (i=0; i<128; i+=2) {
        gfx_->renderQuad(new ncQuad(i,      i,      this->pixelWidth()-2*i,     this->pixelHeight()-2*i,     RGBA(0,0,0,255)));
        gfx_->renderQuad(new ncQuad(i+1,    i+1,    this->pixelWidth()-2*(i+1), this->pixelHeight()-2*(i+1), RGBA(255,0,0,255)));
    }
    gfx_->renderQuad(
        new ncQuad(
            this->pixelWidth()  /2 - 128.f,
            this->pixelHeight() /2 - 128.f,
            256.f,
            256.f,
            RGBA(255,255,255,255),
            tex_
        )
    );
    gfx_->endScene();
}

int ncOpenGLWidget::pixelWidth() {
    return this->width() * QGuiApplication::primaryScreen()->devicePixelRatio();
}

int ncOpenGLWidget::pixelHeight() {
    return this->height() * QGuiApplication::primaryScreen()->devicePixelRatio();
}
