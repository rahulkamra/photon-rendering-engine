#version 330
#include "electron.vsh"

void main()
{
	vec4 v = vec4(position ,1.0);
    gl_Position = mvp*v;
	color =  inColor;
}