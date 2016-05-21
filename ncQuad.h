#ifndef NCQUAD_H
#define NCQUAD_H

#include "ncVertex.h"

class ncQuad {
public:
    ncVertex    v[4];

    ncQuad(float ox, float oy, float w, float h, unsigned int color);
};

#endif//NCQUAD_H
