#include "RenderUtil.h"

RenderUtil::RenderUtil() {
    
}

void RenderUtil::clearScreen()
{
    //TODO: Stencil Buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderUtil::setClearColor(Vector3f color){
    glClearColor(color.getX(), color.getY(), color.getZ(), 1.0f);
}

void RenderUtil::initGraphics()
{
    RenderUtil::setClearColor(Vector3f(0.0, 0.0f, 0.0));

    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);

    //TODO: Depth Clamp for later

    glEnable(GL_FRAMEBUFFER_SRGB);
}

void RenderUtil::unbindTextures()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
