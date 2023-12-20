#version 330 core

out vec4 FragColor;
in vec2 TexCoord;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main() {
    // Mix is GLSL for mixing values of one texture with another by a certain percentage as third argument.
    FragColor = mix(texture(texture1, TexCoord),texture(texture2,TexCoord), 0.5); 
}