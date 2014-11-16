#version 330
#include "electron.fsh"
#include "lighting.fsh"
void main()
{
	//finalColor = texture2D(diffuse,uv.xy)*vec4(ambientLight,1);
	finalColor =  vec4(color*ambientLight,1.0);
}