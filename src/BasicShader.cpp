#include "BasicShader.h"

BasicShader::BasicShader(): Shader() {
    addVertexShader("../../res/shaders/basicVertexShader.vert");
    addFragmentShader("../../res/shaders/basicFragmentShader.frag");
    linkShaders();

    addUniform("transform");
    addUniform("color");
    addUniform("hasTexture");
}

void BasicShader::updateUniforms(Matrix4f worldMatrix, Matrix4f projectedMatrix, Material material)
{
    if(material.getTexture()) material.getTexture()->bind();
    else RenderUtil::unbindTextures();

    setUniformb("hasTexture", material.getTexture() != nullptr);
    setUniform("transform", projectedMatrix);
    setUniform("color", material.getColor());
}
