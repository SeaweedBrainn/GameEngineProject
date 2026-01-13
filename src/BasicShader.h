#pragma once
#include "Shader.h"
#include "RenderUtil.h"

class BasicShader: public Shader{
public:
    BasicShader();
    void updateUniforms(Matrix4f worldMatrix, Matrix4f projectedMatrix, Material material);
private:

};
