#version 330 core

in vec2 texCoords;

out vec4 fragColor;

uniform bool hasTexture;
uniform sampler2D texture1;
uniform vec3 color;

void main() {
    vec4 texColor = hasTexture ? texture(texture1, texCoords) : vec4(1.0);
    fragColor = texColor * vec4(color, 1.0);
}