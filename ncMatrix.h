#ifndef NCMATRIX_H
#define NCMATRIX_H

class ncMatrix {
public:
    union {
        struct {
            float m11, m12, m13, m14;
            float m21, m22, m23, m24;
            float m31, m32, m33, m34;
            float m41, m42, m43, m44;
        };
        struct {
            float m[4][4];
        };
    };

                ncMatrix();
    explicit    ncMatrix(
        float f11, float f12, float f13, float f14,
        float f21, float f22, float f23, float f24,
        float f31, float f32, float f33, float f34,
        float f41, float f42, float f43, float f44
    );

    operator float*();
    operator float const*() const;

    static ncMatrix zero();
    static ncMatrix identity();
};

#endif//NCMATRIX_H
