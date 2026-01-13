#pragma once
#include "Shader.h"
#include "Material.h"

class Matrix4f;

class BasicShader: public Shader{
public:
    BasicShader();
    void updateUniforms(const Matrix4f worldMatrix, const Matrix4f projectedMatrix, const Material& material = Material());
private:

};
