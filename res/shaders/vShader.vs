#version 330 core
layout (location = 0) in vec3 aPos;

out vec4 vertexColor;

uniform mat4 transform;

void main(){
    gl_Position = transform * vec4(aPos, 1.0f);
    vertexColor = vec4(clamp(aPos, 0.0f, 1.0f), 1.0f);
}