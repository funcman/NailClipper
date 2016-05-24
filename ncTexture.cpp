#include "ncTexture.h"
#include <QtOpenGL/QGL>

static int powerOfTwo(int num) {
    int r = 2;
    for (;r<num;) {
        r <<= 1;
    }
    return r;
}

ncTexture::ncTexture(char const* filename) {
    this->textures = new unsigned int;
    *(this->textures) = 0;

    QImage img = QImage(filename).convertToFormat(QImage::Format_RGBA8888);
    if (!img.isNull()) {
        this->original_width    = img.width();
        this->original_height   = img.height();
        this->width             = powerOfTwo(this->original_width);
        this->height            = powerOfTwo(this->original_height);

        unsigned int* data      = new unsigned int[this->width*this->height];
        memset(data, 128, this->width*this->height*sizeof(unsigned int));
        for (int l=0; l<img.height(); ++l) {
            memcpy(data+this->original_width*(this->original_height-l-1), img.constScanLine(l), img.width()*sizeof(unsigned int));
        }
        glGenTextures(1, this->textures);
        glBindTexture(GL_TEXTURE_2D, *(this->textures));
        glTexImage2D(
            GL_TEXTURE_2D,
            0,
            GL_RGBA,
            this->width,
            this->height,
            0,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            data
        );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glBindTexture(GL_TEXTURE_2D, 0);

        delete[] data;
    }
}

ncTexture::~ncTexture() {
    glDeleteTextures(1, this->textures);
    delete this->textures;
}

int ncTexture::getWidth(bool useOriginal) {
    return useOriginal ? this->original_width : this->width;
}

int ncTexture::getHeight(bool useOriginal) {
    return useOriginal ? this->original_height : this->height;
}

unsigned int ncTexture::handle() {
    return *(this->textures);
}
