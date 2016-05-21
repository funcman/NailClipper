#ifndef NCTRIPLE_H
#define NCTRIPLE_H

#include "ncVertex.h"

class ncTriple {
public:
    ncVertex    v[3];

    ncTriple(float x1, float y1, float x2, float y2, float x3, float y3, unsigned int color);
};

#endif//NCTRIPLE_H
