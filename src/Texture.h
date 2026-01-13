#pragma once
#include <glad/glad.h>
#include "ResourceLoader.h"
#include "stb_image.h"

class Texture {
private:
    GLuint ID = 0;
public:
    Texture();
    Texture(const char* texturePath);
    ~Texture();
    GLuint getID();
    void setID(GLuint& value);
    void bind(GLenum textureNum = GL_TEXTURE0);
    void setTexture(const char* texturePath);

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;
};
