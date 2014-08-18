#version 330
#include "electron.fsh"
#include "lighting.fsh"
#include "lightingMath.fsh"

uniform DirectionalLight directionalLight;

void main()
{
	//finalColor =  vec4(color*ambientLight,1.0);
	finalColor = vec4(calculateLight(directionalLight.direction,worldNormal,worldPosition),0);
	//finalColor =  vec4(color*directionalLight.direction,1.0);
	
	
}
