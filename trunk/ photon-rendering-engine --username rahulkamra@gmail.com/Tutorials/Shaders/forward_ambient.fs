#version 330
#include "electron.fsh"
#include "lighting.fsh"
void main()
{
	finalColor =  vec4(color*ambientLight,1.0);
}