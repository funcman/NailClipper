#include "ncQuad.h"

ncQuad::ncQuad(float ox, float oy, float w, float h, unsigned int color) {
    float x1    = ox;
    float y1    = oy;
    float x2    = ox + w;
    float y2    = oy + h;
    float tmp;
    if (x1 > x2) {
        tmp     = x1;
        x1      = x2;
        x2      = tmp;
    }
    if (y1 > y2) {
        tmp     = y1;
        y1      = y2;
        y2      = tmp;
    }
    v[0].set(x1, y1, color);
    v[1].set(x2, y1, color);
    v[2].set(x2, y2, color);
    v[3].set(x1, y2, color);
}
