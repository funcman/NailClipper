#ifndef NCVERTEX_H
#define NCVERTEX_H

class ncVertex {
public:
    float   x;
    float   y;
    float   z;
    float   red;
    float   green;
    float   blue;
    float   alpha;
    float   tx;
    float   ty;

    ncVertex();
    ncVertex(float x, float y, unsigned int color=0x000000FF, float tx=0.f, float ty=0.f);
    ncVertex(float x, float y, float z, unsigned int color=0x000000FF, float tx=0.f, float ty=0.f);

    void set(float x, float y, unsigned int color=0x000000FF, float tx=0.f, float ty=0.f);
    void set(float x, float y, float z, unsigned int color=0x000000FF, float tx=0.f, float ty=0.f);
};

#endif//NCVERTEX_H
