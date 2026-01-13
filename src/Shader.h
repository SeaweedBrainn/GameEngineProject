#pragma once
#include <string>
#include <glad/glad.h>
#include <unordered_map>
#include "Material.h"

class Vector3f;
class Matrix4f;

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
    void updateUniforms(const Matrix4f worldMatrix, const Matrix4f projectedMatrix, const Material& material = Material());
    void addUniform(const std::string &uniform);
    void setUniformb(const std::string &uniformName, bool value) const;
    void setUniformi(const std::string &uniformName, int value) const;
    void setUniformf(const std::string &uniformName, float value) const;
    void setUniform(const std::string &uniformName, Vector3f value) const;
    void setUniform(const std::string &uniformName, Matrix4f value) const;

    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;

    Shader(Shader&& other) noexcept;
    Shader& operator=(Shader&& other) noexcept;
private:
    GLuint ID = 0;
    std::unordered_map<std::string, GLint> uniforms;
};
