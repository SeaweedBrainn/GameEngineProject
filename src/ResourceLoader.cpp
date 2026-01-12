#include "ResourceLoader.h"

void ResourceLoader::loadShader(const char *shaderFilePath, std::string &stringShaderCode)
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
            vertices.emplace_back(Vector3f(x,y,z));
        }

        else if(type == "f"){
            unsigned int a,b,c;
            ss >> a >> b >> c;
            indices.push_back(a-1);
            indices.push_back(b-1);
            indices.push_back(c-1);
        }
    }
    mesh.addVertices(vertices, indices);
}

std::string ResourceLoader::getFileExtension(const char* filePath){
    std::string s = filePath;

    auto pos = s.find_last_of('.');
    if (pos == std::string::npos)
        return "";
    return s.substr(pos + 1);
}
