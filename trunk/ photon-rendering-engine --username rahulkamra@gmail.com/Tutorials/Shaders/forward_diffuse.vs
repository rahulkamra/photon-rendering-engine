#version 330
#include "electron.vsh"

layout (location = 3) in vec2 texCoord;
out vec2 uv;

void main()
{
	vec4 v = vec4(position ,1.0);
    gl_Position = mvp*v;
	color =  inColor;
	uv = texCoord;
}