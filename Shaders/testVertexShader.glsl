#version 300 es

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

uniform mat4 projection;
uniform mat4 transform;
uniform mat4 modelView;

out vec3 Normal;
out vec3 FragPos;

void main(){
    gl_Position = projection * transform * modelView * vec4(position, 1.0);
    FragPos = vec3(modelView * vec4(position, 1.0));
    Normal = vec3(modelView * vec4(normal, 1.0));
}