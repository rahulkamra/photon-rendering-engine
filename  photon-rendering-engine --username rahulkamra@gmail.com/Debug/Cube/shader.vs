#version 330

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 InColor;
uniform vec3 redColor;
uniform  mat4  transformMatrix;

out vec4 Color;

void main()
{
	vec4 v = vec4(Position ,1.0);
    gl_Position = transformMatrix*v;
	Color = vec4(InColor,1.0);
}