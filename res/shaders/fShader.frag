#version 330 core
in vec4 vertexColor;

out vec4 fragColor;

uniform sampler2D texture1;
in vec2 texCoords;

void main(){
    fragColor = texture(texture1, texCoords) * vertexColor;
}