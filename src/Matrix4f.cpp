#include "Matrix4f.h"

void Matrix4f::flattenData()
{
    flattenedData.clear();
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
           flattenedData.push_back(m[i][j]);
        }
    }
}

Matrix4f::Matrix4f() : m(4, _1dFloatVector(4, 0.0f))
{
}

const _2dFloatVector& Matrix4f::getM() const
{
    return m;
}

void Matrix4f::setM(const _2dFloatVector& m)
{
    this->m = m;
    flattenData();
}

float Matrix4f::get(int x, int y) const
{
    return m[x][y];
}

void Matrix4f::set(int x, int y, float val)
{
    m[x][y] = val;
    flattenedData[x * 4 + y] = val;
}

float *Matrix4f::getData()
{
    return flattenedData.data();
}

Matrix4f Matrix4f::initIdentity()
{
    m[0][0] = 1;    m[0][1] = 0;    m[0][2] = 0;    m[0][3] = 0;
    m[1][0] = 0;    m[1][1] = 1;    m[1][2] = 0;    m[1][3] = 0;
    m[2][0] = 0;    m[2][1] = 0;    m[2][2] = 1;    m[2][3] = 0;
    m[3][0] = 0;    m[3][1] = 0;    m[3][2] = 0;    m[3][3] = 1;

    flattenData();
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

Matrix4f Matrix4f::initTranslation(float x, float y, float z)
{
    m[0][0] = 1;    m[0][1] = 0;    m[0][2] = 0;    m[0][3] = x;
    m[1][0] = 0;    m[1][1] = 1;    m[1][2] = 0;    m[1][3] = y;
    m[2][0] = 0;    m[2][1] = 0;    m[2][2] = 1;    m[2][3] = z;
    m[3][0] = 0;    m[3][1] = 0;    m[3][2] = 0;    m[3][3] = 1;

    flattenData();
    return *this;
}
