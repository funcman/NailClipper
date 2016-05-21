#include "ncMatrix.h"

ncMatrix::ncMatrix() {
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            m[i][j] = 0;
        }
    }
}

ncMatrix::ncMatrix(
    float f11, float f12, float f13, float f14,
    float f21, float f22, float f23, float f24,
    float f31, float f32, float f33, float f34,
    float f41, float f42, float f43, float f44
)
:   m11(f11), m12(f12), m13(f13), m14(f14)
,   m21(f21), m22(f22), m23(f23), m24(f24)
,   m31(f31), m32(f32), m33(f33), m34(f34)
,   m41(f41), m42(f42), m43(f43), m44(f44) {
}

ncMatrix::operator float*() {
    return &m11;
}

ncMatrix::operator float const*() const {
    return &m11;
}

ncMatrix ncMatrix::zero() {
    return ncMatrix(
        0.f, 0.f, 0.f, 0.f,
        0.f, 0.f, 0.f, 0.f,
        0.f, 0.f, 0.f, 0.f,
        0.f, 0.f, 0.f, 0.f
    );
}

ncMatrix ncMatrix::identity() {
    return ncMatrix(
        1.f, 0.f, 0.f, 0.f,
        0.f, 1.f, 0.f, 0.f,
        0.f, 0.f, 1.f, 0.f,
        0.f, 0.f, 0.f, 1.f
    );
}
