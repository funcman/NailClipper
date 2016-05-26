#include "ncTriple.h"

ncTriple::ncTriple(float x1, float y1, float x2, float y2, float x3, float y3,
                   unsigned int color,
                   ncTexture* tex, float tx1, float ty1, float tx2, float ty2, float tx3, float ty3,
                   int blend,
                   float z) {
    v[0].set(x1, y1, z, color, tx1, ty1);
    v[1].set(x2, y2, z, color, tx2, ty2);
    v[2].set(x3, y3, z, color, tx3, ty3);
    this->tex       = tex;
    this->blendMode = blend;
}
