#version 330
#include "electron.fsh"
#include "lighting.fsh"
#include "lightingMath.fsh"

uniform DirectionalLight directionalLight;

void main()
{
	//light vector is opposite to the light direction
	finalColor = vec4(calculateLight(directionalLight.direction,worldNormal,worldPosition,directionalLight.light.color),0);
}
