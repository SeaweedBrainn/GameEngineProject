#pragma once
#include <cmath>
#include <vector>

#define _1dFloatVector std::vector<float>
#define _2dFloatVector std::vector<_1dFloatVector>

class Matrix4f {
private:
    _2dFloatVector m;
public:
    Matrix4f();
    const _2dFloatVector& getM() const;
    void setM(const _2dFloatVector& m);
    float get(int x, int y) const;
    void set(int x, int y, float val);
    Matrix4f initIdentity();
    Matrix4f operator*(const Matrix4f& other) const;
};
