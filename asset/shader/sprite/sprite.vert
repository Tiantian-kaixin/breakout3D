#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTex;

uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;

out vec2 texCord;

void main() {
    gl_Position = projection * model * vec4(aPos, 1.f);
    texCord = aTex;
}