#ifndef NCGRAPHICS_H
#define NCGRAPHICS_H

#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include "ncVertex.h"
#include "ncTriple.h"
#include "ncQuad.h"

#define RGBA(r,g,b,a)   (((unsigned int)(a)<<24) + ((unsigned int)(b)<<16) + ((unsigned int)(g)<<8) + (unsigned int)(r))
#define GETR(col)       ((col)       & 0xFF)
#define GETG(col)       (((col)>>8)  & 0xFF)
#define GETB(col)       (((col)>>16) & 0xFF)
#define GETA(col)       ((col)>>24)
#define SETR(col,r)     (((col) & 0xFFFFFF00) +  (unsigned int)(r))
#define SETG(col,g)     (((col) & 0xFFFF00FF) + ((unsigned int)(g)<<8))
#define SETB(col,b)     (((col) & 0xFF00FFFF) + ((unsigned int)(b)<<16))
#define SETA(col,a)     (((col) & 0x00FFFFFF) + ((unsigned int)(a)<<24))

class ncGraphics {
public:
    ncGraphics();
    ~ncGraphics();

    void resize(int w, int h);
    void beginScene();
    void endScene();
    void clear(unsigned int color);
    void renderTriple(ncTriple const* triple);
    void renderQuad(ncQuad const* quad);

private:
    GLushort*                   indexes_;
    ncVertex*                   vertArray_;
    QOpenGLVertexArrayObject    vao_;
    QOpenGLBuffer               ibo_;
    QOpenGLBuffer               vbo_;
    QOpenGLShaderProgram*       program_;

    int                         numPrim_;
    int                         curPrimType_;

    void    renderBatch();
    QString readCodeFromFile(QString const& shaderFile);
    bool    prepareShaderProgram(QString const& vertexShaderPath, QString const& fragmentShaderPath);
};

#endif//NCGRAPHICS_H
