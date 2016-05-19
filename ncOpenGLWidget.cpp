#include "ncOpenGLWidget.h"

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
}

bool ncOpenGLWidget::prepareShaderProgram(QString const& vertexShaderPath, QString const& fragmentShaderPath) {
    bool result = program_->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexShaderPath);
    if (!result) {
        qWarning() << "Could not add vertex shader program:" << program_->log();
    }

    result = program_->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentShaderPath);
    if (!result) {
        qWarning() << "Could not add fragment shader program:" << program_->log();
    }

    result = program_->link();
    if (!result) {
        qWarning() << "Could not link shader program:" << program_->log();
    }

    return result;
}
