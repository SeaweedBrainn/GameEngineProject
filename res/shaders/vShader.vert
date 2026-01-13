#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec4 vertexColor;
out vec2 texCoords;

uniform mat4 transform;

void main(){
    gl_Position = transform * vec4(aPos, 1.0f);
    vertexColor = transform * vec4(clamp(aPos, 0.0f, 1.0f), 1.0f);
    texCoords = aTexCoords;
}