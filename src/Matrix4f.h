#pragma once
#include <vector>

class Vector3f;

typedef std::vector<float> _1dFloatVector;
typedef std::vector<_1dFloatVector> _2dFloatVector;

class Matrix4f {
private:
    _2dFloatVector m;
    _1dFloatVector flattenedData;
    void flattenData();
public:
    Matrix4f();
    const _2dFloatVector& getM() const;
    void setM(const _2dFloatVector& m);
    float get(int x, int y) const;
    void set(int x, int y, float val);
    float* getData();
    Matrix4f initIdentity();
    Matrix4f operator*(const Matrix4f& other) const;

    Matrix4f initTranslation(float x, float y, float z);
    Matrix4f initRotation(float x, float y, float z);
    Matrix4f initScale(float x, float y, float z);
    Matrix4f initProjection(float fov, float width, float height, float zNear, float zFar);
    Matrix4f initCamera(Vector3f forward, Vector3f up);
};
