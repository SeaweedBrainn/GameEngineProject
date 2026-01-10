#include "Shader.h"

Shader::Shader() {
    ID = glCreateProgram();
}

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    if(ID == 0) ID = glCreateProgram();

    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try{
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }

    catch(std::ifstream::failure e){
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        exit(-1);
    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    int success;
    char infoLog[512];

    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(-1);
    }

    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(-1);
    }

    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        exit(-1);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::Shader(const char *vertexPath, const char* geometryPath, const char *fragmentPath)
{
    if(ID == 0) ID = glCreateProgram();

    std::string vertexCode;
    std::string fragmentCode;
    std::string geometryCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    std::ifstream gShaderFile;

    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    gShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try{
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        gShaderFile.open(geometryPath);
        
        std::stringstream vShaderStream, fShaderStream, gShaderStream;

        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        gShaderStream << gShaderFile.rdbuf();

        vShaderFile.close();
        fShaderFile.close();
        gShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
        geometryCode = gShaderStream.str();
    }

    catch(std::ifstream::failure e){
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        exit(-1);
    }

    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    const char* gShaderCode = geometryCode.c_str();

    int success;
    char infoLog[512];

    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(-1);
    }

    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(-1);
    }

    GLuint geometryShader;
    geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
    glShaderSource(geometryShader, 1, &gShaderCode, NULL);
    glCompileShader(geometryShader);

    glGetShaderiv(geometryShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(geometryShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::GEOMETRY::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(-1);
    }

    glAttachShader(ID, vertexShader);
    glAttachShader(ID, geometryShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        exit(-1);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glDeleteShader(geometryShader);
}

Shader::~Shader()
{
    //glDeleteProgram(ID);
}

void Shader::addVertexShader(const char* filePath)
{
    addShader(filePath, GL_VERTEX_SHADER);
}

void Shader::addGeometryShader(const char* filePath)
{
    addShader(filePath, GL_GEOMETRY_SHADER);
}

void Shader::addFragmentShader(const char* filePath)
{
    addShader(filePath, GL_FRAGMENT_SHADER);
}

void Shader::addShader(const char* filePath, GLenum shader_type)
{
    std::string code;
    std::ifstream shaderFile;

    shaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try{
        shaderFile.open(filePath);

        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();

        code = shaderStream.str();
    }

    catch(std::ifstream::failure e){
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }

    const char*  shaderCode = code.c_str();
    
    int success;
    char infoLog[512];

    GLuint shader;
    shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &shaderCode, NULL);
    glCompileShader(shader);

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << shader_type << "::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(-1);
    }

    glAttachShader(ID, shader);
    glDeleteShader(shader);
}

void Shader::linkShaders()
{
    int success;
    char infoLog[512];

    glLinkProgram(ID);
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success){
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::LINKING_FAILED\n" << infoLog << std::endl;
        exit(-1);
    }
}

void Shader::bind()
{
    glUseProgram(ID);
}

void Shader::addUniform(const std::string &uniformName)
{
    GLint uniformLocation = glGetUniformLocation(ID, uniformName.c_str());
    if(uniformLocation == -1){
        std::cerr << "ERROR: Could not find uniform " << uniformName << std::endl;
        exit(-1);
    }
    uniforms.insert({uniformName, uniformLocation});
}

void Shader::setUniformb(const std::string &uniformName, bool value) const
{   
    glUniform1i(uniforms.at(uniformName), (int)value); 
}

void Shader::setUniformi(const std::string &uniformName, int value) const
{   
    glUniform1i(uniforms.at(uniformName), value); 
}

void Shader::setUniformf(const std::string &uniformName, float value) const
{   
    glUniform1f(uniforms.at(uniformName), value); 
}

void Shader::setUniform(const std::string &uniformName, Vector3f value) const
{
    glUniform3f(uniforms.at(uniformName), value.getX(), value.getY(), value.getZ());
}

void Shader::setUniform(const std::string &uniformName, Matrix4f value) const
{
    glUniformMatrix4fv(uniforms.at(uniformName), 1, GL_TRUE, value.getData());
}
