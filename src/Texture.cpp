#include "Texture.h"

Texture::Texture()
{
    glGenTextures(1, &ID);
}

Texture::Texture(const char *texturePath)
{
    if(ID == 0) glGenTextures(1, &ID);
    setTexture(texturePath);
}

Texture::~Texture()
{
    glDeleteTextures(1, &ID);
}

GLuint Texture::getID() {
    return ID;
}

void Texture::setID(GLuint& value) {
    ID = value;
}

void Texture::bind(GLenum textureNum)
{
    glActiveTexture(textureNum);
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::setTexture(const char *texturePath)
{
    int width, height, nrChannels;
    unsigned char* data;
    
    ResourceLoader::loadTexture(texturePath, data, width, height, nrChannels);

    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    GLenum format;
    switch (nrChannels) {
        case 1: format = GL_RED;       break;
        case 2: format = GL_RG;        break;
        case 3: format = GL_RGB;       break;
        case 4: format = GL_RGBA;      break;
        default:
            std::cerr << "Unsupported number of channels: " << nrChannels << std::endl;
            stbi_image_free(data);
            exit(1);
    }
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(data);
}
