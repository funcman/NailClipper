#include "ncOpenGLWidget.h"
#include <QFile>

ncOpenGLWidget::ncOpenGLWidget(QWidget* parent)
:   QOpenGLWidget(parent)
,   program_(0) {
}

ncOpenGLWidget::~ncOpenGLWidget() {
    this->makeCurrent();

    delete program_;
    vbo_.destroy();
    vao_.destroy();

    this->doneCurrent();
}

void ncOpenGLWidget::initializeGL() {
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    vao_.create();
    if (vao_.isCreated()) {
        vao_.bind();
    }

    float vertices[] = {
        -0.5f,  0.5f, 1.0f,
         0.5f,  0.5f, 1.0f,
         0.5f, -0.5f, 1.0f,
        -0.5f, -0.5f, 1.0f,
    };

    vbo_.create();
    vbo_.bind();
    vbo_.setUsagePattern(QOpenGLBuffer::StaticDraw);
    int vertices_num    = 4;
    int vertex_size     = sizeof(float) * 3;
    vbo_.allocate(vertices, vertex_size*vertices_num);

    program_ = new QOpenGLShaderProgram();
    if (!prepareShaderProgram(":/vertex.glsl", ":/fragment.glsl")) {
        return;
    }
    program_->bind();
    program_->setAttributeBuffer("vertices", GL_FLOAT, 0, 3);
    program_->enableAttributeArray("vertices");
}

void ncOpenGLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, qMax(h, 1));
}

void ncOpenGLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glFlush();
}

QString ncOpenGLWidget::readCodeFromFile(QString const& shaderFile) {
    QString out;
#if defined(Q_OS_IOS) || defined(Q_OS_ANDROID)
    out.append("#version 300 es\n");
#else
    out.append("#version 330 core\n");
#endif
    QFile file(shaderFile);
    if (!file.open(QFile::ReadOnly|QFile::Text)) {
        qWarning() << "Could not open shader program file: " << shaderFile;
        return QString::null;
    }
    QTextStream in(&file);
    out.append(in.readAll());
    return out;
}

bool ncOpenGLWidget::prepareShaderProgram(QString const& vertexShaderPath, QString const& fragmentShaderPath) {
    QString vertexShaderCode = this->readCodeFromFile(vertexShaderPath);
    if (vertexShaderCode.isNull()) {
        return false;
    }
    if (!program_->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderCode)) {
        qWarning() << "Could not add vertex shader program:" << program_->log();
        return false;
    }

    QString fragmentShaderCode = this->readCodeFromFile(fragmentShaderPath);
    if (fragmentShaderCode.isNull()) {
        return false;
    }
    if (!program_->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderCode)) {
        qWarning() << "Could not add fragment shader program:" << program_->log();
        return false;
    }

    if (!program_->link()) {
        qWarning() << "Could not link shader program:" << program_->log();
        return false;
    }

    return true;
}
