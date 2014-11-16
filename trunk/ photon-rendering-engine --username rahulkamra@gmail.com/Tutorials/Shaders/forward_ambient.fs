#version 330
#include "electron.fsh"
#include "lighting.fsh"

uniform sampler2D diffuse;

void main()
{
	//finalColor = texture2D(diffuse,uv.xy)*vec4(ambientLight,1);
	//if(diffuse)
	//{
		finalColor = texture2D(diffuse,uv.xy)*vec4(ambientLight,1);
	//}
	//else
	//{
		//finalColor =  vec4(color*ambientLight,1.0);
	//}
		
	
		
}