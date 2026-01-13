#include "BasicShader.h"
#include "RenderUtil.h"
#include "Matrix4f.h"

BasicShader::BasicShader(): Shader("../../res/shaders/basicVertexShader.vert","../../res/shaders/basicFragmentShader.frag") {
    addUniform("transform");
    addUniform("color");
    addUniform("hasTexture");
}

void BasicShader::updateUniforms(const Matrix4f worldMatrix, const Matrix4f projectedMatrix, const Material& material)
{
    if(material.getTexture().getID()) material.getTexture().bind();
    else RenderUtil::unbindTextures();

    setUniformb("hasTexture", material.getTexture().getID());
    setUniform("transform", projectedMatrix);
    setUniform("color", material.getColor());
}
