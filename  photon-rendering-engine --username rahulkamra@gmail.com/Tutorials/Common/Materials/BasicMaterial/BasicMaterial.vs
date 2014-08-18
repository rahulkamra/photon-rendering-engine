#version 330

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 InColor;
layout (location = 2) in vec3 normal;

uniform vec3 redColor;
uniform  mat4  worldToView;
uniform  mat4  modelToWorld;

uniform  vec3   ambientLight;
uniform  vec3   directionalLight;
out vec3 Color;

void main()
{
	vec4 v = vec4(Position ,1.0);
    gl_Position = worldToView*v;
	Color =  InColor;
}