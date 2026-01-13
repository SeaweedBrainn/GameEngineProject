#include "ResourceLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Vertex.h"
#include "Mesh.h"

void ResourceLoader::loadShaderCode(const char *shaderFilePath, std::string &stringShaderCode)
{
    ResourceLoader::loadTextFileContents(shaderFilePath, stringShaderCode);
}

void ResourceLoader::loadTextFileContents(const char *filePath, std::string &content)
{
    std::ifstream fileHandle;

    fileHandle.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try{
        fileHandle.open(filePath);

        std::stringstream shaderStream;
        shaderStream << fileHandle.rdbuf();
        fileHandle.close();

        content = shaderStream.str();
    }

    catch(std::ifstream::failure e){
        std::cerr << "ERROR::FILE_NOT_SUCCESFULLY_READ " << filePath << std::endl;
        exit(1);
    }
}

void ResourceLoader::loadMesh(const char *meshPath, Mesh& mesh)
{
    std::string ext = ResourceLoader::getFileExtension(meshPath);

    if(ext != std::string("obj")){
        std::cerr << "Mesh format not supported: " << ext << std::endl;
        exit(1);
    }

    vertexList vertices;
    indexList indices;
    std::vector<Vector3f> vertexCoords;
    std::vector<Vector2f> texCoords;
    std::string meshData;
    loadTextFileContents(meshPath, meshData);

    std::istringstream input(meshData);
    std::string line;

    while(std::getline(input, line)){
        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if(type == "v"){
            float x, y, z;
            ss >> x >> y >> z;
            vertexCoords.emplace_back(x,y,z);
            vertices.emplace_back(Vector3f(x,y,z));
        }

        else if(type == "f"){
            unsigned int a,b,c;
            ss >> a >> b >> c;
            indices.push_back(a-1);
            indices.push_back(b-1);
            indices.push_back(c-1);
        }

        else if(type == "vt"){
            float x, y;
            ss >> x >> y;
            texCoords.emplace_back(x,y);
        }
    }

    if(texCoords.size() == 0){
        mesh.addVertices(vertices, indices);
        return;
    }

    vertices.clear();
    for(int i = 0; i < vertexCoords.size(); i++){
        vertices.emplace_back(vertexCoords[i], texCoords[i]);
    }
    mesh.addVertices(vertices, indices);
    return;
}

void ResourceLoader::loadTexture(const char *texturePath, unsigned char*& textureData, int& width, int& height, int& nrChannels)
{
    stbi_set_flip_vertically_on_load(true);
    textureData = stbi_load(texturePath, &width, &height, &nrChannels, 0);

    if(!textureData){
        std::cerr << "ERROR::TEXTURE::FILE_NOT_SUCCESFULLY_READ " << texturePath << std::endl;
        exit(1);
    }
}

std::string ResourceLoader::getFileExtension(const char* filePath){
    std::string s = filePath;

    auto pos = s.find_last_of('.');
    if (pos == std::string::npos)
        return "";
    return s.substr(pos + 1);
}
