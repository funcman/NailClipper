#include "ncVertex.h"

union C {
    struct {
        unsigned char   red;
        unsigned char   green;
        unsigned char   blue;
        unsigned char   alpha;
    };
    unsigned int color;
};

static void COLOR_UINT32_TO_FLOAT4(unsigned int color, float* red, float* green, float* blue, float* alpha) {
    union C c;
    c.color = color;
    *red    = c.red     / 255.f;
    *green  = c.green   / 255.f;
    *blue   = c.blue    / 255.f;
    *alpha  = c.alpha   / 255.f;
}

ncVertex::ncVertex() {
    ncVertex(0.f, 0.f);
}

ncVertex::ncVertex(float x, float y, unsigned int color, float tx, float ty) {
    ncVertex(x, y, 0.f, color, tx, ty);
}

ncVertex::ncVertex(float x, float y, float z, unsigned int color, float tx, float ty)
:   x(x)
,   y(y)
,   z(z)
,   tx(tx)
,   ty(ty) {
    COLOR_UINT32_TO_FLOAT4(color, &this->red, &this->green, &this->blue, &this->alpha);
}

void ncVertex::set(float x, float y, unsigned int color, float tx, float ty) {
    this->set(x, y, 0.f, color, tx, ty);
}

void ncVertex::set(float x, float y, float z, unsigned int color, float tx, float ty) {
    this->x     = x;
    this->y     = y;
    this->z     = z;
    COLOR_UINT32_TO_FLOAT4(color, &this->red, &this->green, &this->blue, &this->alpha);
    this->tx    = tx;
    this->ty    = ty;
}
