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
    const GLuint getID() const;
    void setID(GLuint& value);
    void bind(GLenum textureNum = GL_TEXTURE0) const;
    void setTexture(const char* texturePath);

    Texture(Texture &&other) noexcept;
    Texture &operator=(Texture &&other) noexcept;

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;
};
