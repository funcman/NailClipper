#ifndef NCOPENGLWIDGET_H
#define NCOPENGLWIDGET_H

#include <QOpenGLWidget>

class ncGraphics;
class ncTexture;

class ncOpenGLWidget : public QOpenGLWidget {
    Q_OBJECT

public:
    explicit ncOpenGLWidget(QWidget* parent=0);
    ~ncOpenGLWidget();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();

private:
    ncGraphics* gfx_;
    ncTexture*  tex_;
};

#endif//NCOPENGLWIDGET_H
