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
    virtual void resizeGL(int, int);
    virtual void paintGL();

private:
    ncGraphics* gfx_;
    ncTexture*  tex_;

    int pixelWidth();
    int pixelHeight();
};

#endif//NCOPENGLWIDGET_H
