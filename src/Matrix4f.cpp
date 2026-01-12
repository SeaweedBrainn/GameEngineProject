#include "Matrix4f.h"

void Matrix4f::flattenData()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
           flattenedData[i * 4 + j] = m[i][j];
        }
    }
}

Matrix4f::Matrix4f() : m(4, _1dFloatVector(4, 0.0f)), flattenedData(16, 0.0f)
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

Matrix4f Matrix4f::initRotation(float x, float y, float z){
    Matrix4f rx, ry, rz;

    x = x * M_PI / 180;
    y = y * M_PI / 180;
    z = z * M_PI / 180;

    rz.m[0][0] = cos(z);    rz.m[0][1] = -sin(z);   rz.m[0][2] = 0;         rz.m[0][3] = 0;
    rz.m[1][0] = sin(z);    rz.m[1][1] = cos(z);    rz.m[1][2] = 0;         rz.m[1][3] = 0;
    rz.m[2][0] = 0;         rz.m[2][1] = 0;         rz.m[2][2] = 1;         rz.m[2][3] = 0;
    rz.m[3][0] = 0;         rz.m[3][1] = 0;         rz.m[3][2] = 0;         rz.m[3][3] = 1;

    rx.m[0][0] = 1;         rx.m[0][1] = 0;         rx.m[0][2] = 0;         rx.m[0][3] = 0;
    rx.m[1][0] = 0;         rx.m[1][1] = cos(x);    rx.m[1][2] = -sin(x);   rx.m[1][3] = 0;
    rx.m[2][0] = 0;         rx.m[2][1] = sin(x);    rx.m[2][2] = cos(x);    rx.m[2][3] = 0;
    rx.m[3][0] = 0;         rx.m[3][1] = 0;         rx.m[3][2] = 0;         rx.m[3][3] = 1;

    ry.m[0][0] = cos(y);    ry.m[0][1] = 0;         ry.m[0][2] = sin(y);    ry.m[0][3] = 0;
    ry.m[1][0] = 0;         ry.m[1][1] = 1;         ry.m[1][2] = 0;         ry.m[1][3] = 0;
    ry.m[2][0] = -sin(y);   ry.m[2][1] = 0;         ry.m[2][2] = cos(y);    ry.m[2][3] = 0;
    ry.m[3][0] = 0;         ry.m[3][1] = 0;         ry.m[3][2] = 0;         ry.m[3][3] = 1;

    *this = rz * ry * rx;
    flattenData();
    return *this;
}

Matrix4f Matrix4f::initScale(float x, float y, float z)
{
    m[0][0] = x;    m[0][1] = 0;    m[0][2] = 0;    m[0][3] = 0;
    m[1][0] = 0;    m[1][1] = y;    m[1][2] = 0;    m[1][3] = 0;
    m[2][0] = 0;    m[2][1] = 0;    m[2][2] = z;    m[2][3] = 0;
    m[3][0] = 0;    m[3][1] = 0;    m[3][2] = 0;    m[3][3] = 1;

    flattenData();
    return *this;
}

Matrix4f Matrix4f::initProjection(float fov, float width, float height, float zNear, float zFar)
{
    float tanHalfFOV = tan((fov/2) * M_PI / 180);
    float ar = width / height;
    float zRange = zNear - zFar;

    m[0][0] = 1 / (tanHalfFOV * ar);        m[0][1] = 0;                m[0][2] = 0;                        m[0][3] = 0;
    m[1][0] = 0;                            m[1][1] = 1 / tanHalfFOV;   m[1][2] = 0;                        m[1][3] = 0;
    m[2][0] = 0;                            m[2][1] = 0;                m[2][2] = -(zNear + zFar)/zRange;   m[2][3] = 2 * zFar * zNear / zRange;
    m[3][0] = 0;                            m[3][1] = 0;                m[3][2] = 1;                        m[3][3] = 0;

    flattenData();
    return *this;
}

Matrix4f Matrix4f::initCamera(Vector3f forward, Vector3f up)
{
    Vector3f f = forward;
    f.normalize();

    Vector3f r = up;
    r.normalize();
    r = r * f;

    Vector3f u = f * r;

    m[0][0] = r.getX();     m[0][1] = r.getY();     m[0][2] = r.getZ();     m[0][3] = 0;
    m[1][0] = u.getX();     m[1][1] = u.getY();     m[1][2] = u.getZ();     m[1][3] = 0;
    m[2][0] = f.getX();     m[2][1] = f.getY();     m[2][2] = f.getZ();     m[2][3] = 0;
    m[3][0] = 0;            m[3][1] = 0;            m[3][2] = 0;            m[3][3] = 1;

    flattenData();
    return *this;
}
