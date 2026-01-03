#include "Matrix4f.h"

Matrix4f::Matrix4f() : m(4, _1dFloatVector(4, 0.0f)) {
}

const _2dFloatVector& Matrix4f::getM() const
{
    return m;
}

void Matrix4f::setM(const _2dFloatVector& m)
{
    this->m = m;
}

float Matrix4f::get(int x, int y) const
{
    return m[x][y];
}

void Matrix4f::set(int x, int y, float val)
{
    m[x][y] = val;
}

Matrix4f Matrix4f::initIdentity()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == j) m[i][j] = 1;
            else m[i][j] = 0;
        }
    }

    return *this;
}

Matrix4f Matrix4f::operator*(const Matrix4f &other) const
{
    Matrix4f res;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            res.set(i, j, m[i][0] * other.get(0,j) + 
                          m[i][1] * other.get(1,j) +
                          m[i][2] * other.get(2,j) +
                          m[i][3] * other.get(3,j));
        }
    }
    return res;
}
