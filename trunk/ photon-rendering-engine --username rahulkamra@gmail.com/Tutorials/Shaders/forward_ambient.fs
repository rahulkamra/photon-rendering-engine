#version 330
#include "electron.fsh"
#include "lighting.fsh"

uniform sampler2D diffuse;
in  vec2  uv;

void main()
{
	//finalColor = texture2D(diffuse,uv.xy)*vec4(ambientLight,1);
	//if(diffuse)
	//{
		finalColor = texture2D(diffuse,uv.xy);//*vec4(ambientLight,uv.y);
	//}
	//else
	//{
		//finalColor =  vec4(color*ambientLight,1.0);
	//}
		
	
		
}