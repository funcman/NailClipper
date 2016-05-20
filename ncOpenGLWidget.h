#ifndef NCOPENGLWIDGET_H
#define NCOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

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
    QOpenGLVertexArrayObject    vao_;
    QOpenGLBuffer               vbo_;
    QOpenGLShaderProgram*       program_;

    QString readCodeFromFile(QString const& shaderFile);
    bool    prepareShaderProgram(QString const& vertexShaderPath, QString const& fragmentShaderPath);
};

#endif//NCOPENGLWIDGET_H
