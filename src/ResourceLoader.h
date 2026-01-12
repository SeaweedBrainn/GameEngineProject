#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Vertex.h"
#include "Mesh.h"

class ResourceLoader {
public:
   static void loadShader(const char* shaderFilePath, std::string& shaderCode);
   static void loadTextFileContents(const char *filePath, std::string &content);
   static void loadMesh(const char *meshPath, Mesh &mesh);
private:
   static std::string getFileExtension(const char *filePath);
};