#ifndef NCQUAD_H
#define NCQUAD_H

#include "ncVertex.h"

class ncTexture;

class ncQuad {
public:
    ncVertex    v[4];
    ncTexture*  tex;

    ncQuad(float ox, float oy, float w, float h, unsigned int color, ncTexture* tex=0);
};

#endif//NCQUAD_H
