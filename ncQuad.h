#ifndef NCQUAD_H
#define NCQUAD_H

#include "ncCommon.h"
#include "ncVertex.h"

class ncTexture;

class ncQuad {
public:
    ncVertex    v[4];
    ncTexture*  tex;
    int         blendMode;

    ncQuad(float ox, float oy, float w, float h, unsigned int color, ncTexture* tex=0, int blend=NC_BLEND_DEFAULT, float z=0.f);
};

#endif//NCQUAD_H
