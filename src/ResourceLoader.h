#pragma once
#include <string>

class Mesh;

class ResourceLoader {
public:
   static void loadShaderCode(const char* shaderFilePath, std::string& shaderCode);
   static void loadTextFileContents(const char *filePath, std::string &content);
   static void loadMesh(const char *meshPath, Mesh &mesh);
   static void loadTexture(const char *texturePath, unsigned char*& textureData, int& width, int& height, int& nrChannels);
private:
   static std::string getFileExtension(const char *filePath);
};