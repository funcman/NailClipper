#include "ncTriple.h"

ncTriple::ncTriple(float x1, float y1, float x2, float y2, float x3, float y3, unsigned int color) {
    v[0].set(x1, y1, color);
    v[1].set(x2, y2, color);
    v[2].set(x3, y3, color);
}
