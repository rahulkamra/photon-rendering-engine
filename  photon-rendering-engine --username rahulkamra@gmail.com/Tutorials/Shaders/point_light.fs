#version 330
#include "electron.fsh"
#include "lighting.fsh"
#include "lightingMath.fsh"

uniform PointLight pointLight;

void main()
{
	vec3 lightVector =  worldPosition - pointLight.position;
	finalColor = calculatePointLight(lightVector,pointLight.attenuation,pointLight.light.color);
}




