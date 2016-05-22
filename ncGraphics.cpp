#include "ncGraphics.h"
#include <QFile>
#include "ncVertex.h"
#include "ncMatrix.h"

#define VERTEX_BUFFER_SIZE  4000

#define PRIM_TRIPLES        3
#define PRIM_QUADS          4

ncGraphics::ncGraphics()
:   ibo_(QOpenGLBuffer::IndexBuffer)
,   vbo_(QOpenGLBuffer::VertexBuffer) {
    indexes_    = new GLubyte[VERTEX_BUFFER_SIZE*6/4];
    vertArray_  = new ncVertex[VERTEX_BUFFER_SIZE];

    GLubyte* iptr   = indexes_;
    GLubyte n       = 0;
    for (int i=0; i<VERTEX_BUFFER_SIZE/4; ++i) {
        *iptr++ = n;
        *iptr++ = n+1;
        *iptr++ = n+2;
        *iptr++ = n+2;
        *iptr++ = n+3;
        *iptr++ = n;
        n+=4;
    }

    vao_.create();

    ibo_.create();
    ibo_.bind();
    ibo_.setUsagePattern(QOpenGLBuffer::StaticDraw);
    ibo_.allocate(indexes_, sizeof(GLubyte)*VERTEX_BUFFER_SIZE*6/4);
    ibo_.release();

    vbo_.create();
    vbo_.bind();
    vbo_.setUsagePattern(QOpenGLBuffer::DynamicDraw);
    vbo_.allocate(sizeof(ncVertex)*VERTEX_BUFFER_SIZE);
    vbo_.release();

    program_ = new QOpenGLShaderProgram();
    if (!prepareShaderProgram(":/vertex.glsl", ":/fragment.glsl")) {
        return;
    }
    program_->bind();
    program_->setUniformValue("projectionMatrix",   QMatrix4x4((float*)ncMatrix::identity()));
    program_->setUniformValue("modelViewMatrix",    QMatrix4x4((float*)ncMatrix::identity()));
    program_->release();

    numPrim_        = 0;
    curPrimType_    = PRIM_QUADS;
}

ncGraphics::~ncGraphics() {
    delete program_;
    vbo_.destroy();
    ibo_.destroy();
    vao_.destroy();
    delete[] vertArray_;
    delete[] indexes_;
}

void ncGraphics::beginScene() {
    vao_.bind();
    ibo_.bind();
    vbo_.bind();
    program_->bind();
}

void ncGraphics::endScene() {
    this->renderBatch();
    program_->release();
    vbo_.release();
    ibo_.release();
    vao_.release();
}

void ncGraphics::clear(unsigned int color) {
    glClearColor(
        GETR(color) / 255.f,
        GETG(color) / 255.f,
        GETB(color) / 255.f,
        GETA(color) / 255.f
    );
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void ncGraphics::renderTriple(ncTriple const* triple) {
    if ((curPrimType_ != PRIM_TRIPLES)
    ||  (numPrim_ >= VERTEX_BUFFER_SIZE/PRIM_TRIPLES)) {
        this->renderBatch();
        curPrimType_ = PRIM_TRIPLES;
    }
    memcpy(&vertArray_[numPrim_*PRIM_TRIPLES], triple->v, sizeof(ncVertex)*PRIM_TRIPLES);
    ++numPrim_;
}

void ncGraphics::renderQuad(ncQuad const* quad) {
    if ((curPrimType_ != PRIM_QUADS)
    ||  (numPrim_ >= VERTEX_BUFFER_SIZE/PRIM_QUADS)) {
        this->renderBatch();
        curPrimType_ = PRIM_QUADS;
    }
    memcpy(&vertArray_[numPrim_*PRIM_QUADS], quad->v, sizeof(ncVertex)*PRIM_QUADS);
    ++numPrim_;
}

void ncGraphics::renderBatch() {
    if (numPrim_ > 0) {
        switch (curPrimType_) {
        case PRIM_TRIPLES: {
            vbo_.write(0, vertArray_, sizeof(ncVertex)*PRIM_TRIPLES*numPrim_);
            program_->setAttributeBuffer("position",    GL_FLOAT, 0,                3, sizeof(ncVertex));
            program_->setAttributeBuffer("color",       GL_FLOAT, sizeof(float)*3,  3, sizeof(ncVertex));
            program_->enableAttributeArray("position");
            program_->enableAttributeArray("color");
            glDrawArrays(GL_TRIANGLES, 0, PRIM_TRIPLES*numPrim_);
        } break;
        case PRIM_QUADS: {
            vbo_.write(0, vertArray_, sizeof(ncVertex)*PRIM_QUADS*numPrim_);
            program_->setAttributeBuffer("position",    GL_FLOAT, 0,                3, sizeof(ncVertex));
            program_->setAttributeBuffer("color",       GL_FLOAT, sizeof(float)*3,  3, sizeof(ncVertex));
            program_->enableAttributeArray("position");
            program_->enableAttributeArray("color");
            glDrawElements(GL_TRIANGLES, numPrim_*6, GL_UNSIGNED_BYTE, 0);
        } break;
        default: break;
        }

        glFlush();
        numPrim_ = 0;
    }
}

QString ncGraphics::readCodeFromFile(QString const& shaderFile) {
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

bool ncGraphics::prepareShaderProgram(QString const& vertexShaderPath, QString const& fragmentShaderPath) {
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
