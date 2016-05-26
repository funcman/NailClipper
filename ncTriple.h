#ifndef NCTRIPLE_H
#define NCTRIPLE_H

#include "ncCommon.h"
#include "ncVertex.h"

class ncTexture;

class ncTriple {
public:
    ncVertex    v[3];
    ncTexture*  tex;
    int         blendMode;

    ncTriple(float x1, float y1, float x2, float y2, float x3, float y3,
             unsigned int color,
             ncTexture* tex=0, float tx1=0.f, float ty1=0.f, float tx2=0.f, float ty2=0.f, float tx3=0.f, float ty3=0.f,
             int blend=NC_BLEND_DEFAULT,
             float z=0.f);
};

#endif//NCTRIPLE_H
