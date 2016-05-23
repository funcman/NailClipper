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

ncMatrix ncMatrix::operator*(ncMatrix const& mat) const {
    return ncMatrix(
        m11 * mat.m11 + m12 * mat.m21 + m13 * mat.m31 + m14 * mat.m41,
        m11 * mat.m12 + m12 * mat.m22 + m13 * mat.m32 + m14 * mat.m42,
        m11 * mat.m13 + m12 * mat.m23 + m13 * mat.m33 + m14 * mat.m43,
        m11 * mat.m14 + m12 * mat.m24 + m13 * mat.m34 + m14 * mat.m44,
        m21 * mat.m11 + m22 * mat.m21 + m23 * mat.m31 + m24 * mat.m41,
        m21 * mat.m12 + m22 * mat.m22 + m23 * mat.m32 + m24 * mat.m42,
        m21 * mat.m13 + m22 * mat.m23 + m23 * mat.m33 + m24 * mat.m43,
        m21 * mat.m14 + m22 * mat.m24 + m23 * mat.m34 + m24 * mat.m44,
        m31 * mat.m11 + m32 * mat.m21 + m33 * mat.m31 + m34 * mat.m41,
        m31 * mat.m12 + m32 * mat.m22 + m33 * mat.m32 + m34 * mat.m42,
        m31 * mat.m13 + m32 * mat.m23 + m33 * mat.m33 + m34 * mat.m43,
        m31 * mat.m14 + m32 * mat.m24 + m33 * mat.m34 + m34 * mat.m44,
        m41 * mat.m11 + m42 * mat.m21 + m43 * mat.m31 + m44 * mat.m41,
        m41 * mat.m12 + m42 * mat.m22 + m43 * mat.m32 + m44 * mat.m42,
        m41 * mat.m13 + m42 * mat.m23 + m43 * mat.m33 + m44 * mat.m43,
        m41 * mat.m14 + m42 * mat.m24 + m43 * mat.m34 + m44 * mat.m44
    );
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

ncMatrix ncMatrix::translate(ncVector const& position) {
    return ncMatrix(
        1.f, 0.f, 0.f, position.x,
        0.f, 1.f, 0.f, position.y,
        0.f, 0.f, 1.f, position.z ,
        0.f, 0.f, 0.f, 1.f
    );
}

ncMatrix ncMatrix::scale(ncVector const& scale) {
    return ncMatrix(
        scale.x,    0.f,        0.f,        0.f,
        0.f,        scale.y,    0.f,        0.f,
        0.f,        0.f,        scale.z,    0.f,
        0.f,        0.f,        0.f,        1.f
    );
}

ncMatrix ncMatrix::ortho(float left, float right, float top, float bottom, float near, float far) {
    return ncMatrix(
        2/(right-left), 0.f,            0.f,            -(right+left)/(right-left),
        0.f,            2/(top-bottom), 0.f,            -(top+bottom)/(top-bottom),
        0.f,            0.f,            -2/(far-near),  -(far+near)/(far-near),
        0.f,            0.f,            0.f,            1.f
    );
}
