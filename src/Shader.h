#pragma once
#include <string>
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include "Vector3f.h"
#include "Matrix4f.h"

class Shader {
public:
    Shader();
    Shader(const char *vertexPath, const char *fragmentPath);
    Shader(const char *vertexPath, const char *geometryPath, const char *fragmentPath);
    ~Shader();
    void addVertexShader(const char* filePath);
    void addGeometryShader(const char* filePath);
    void addFragmentShader(const char* filePath);
    void addShader(const char* filePath, GLenum shader_type);
    void linkShaders();
    void bind();
    void addUniform(const std::string &uniform);
    void setUniformb(const std::string &uniformName, bool value) const;
    void setUniformi(const std::string &uniformName, int value) const;
    void setUniformf(const std::string &uniformName, float value) const;
    void setUniform(const std::string &uniformName, Vector3f value) const;
    void setUniform(const std::string &uniformName, Matrix4f value) const;

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;
private:
    GLuint ID = 0;
    std::unordered_map<std::string, GLint> uniforms;
};
