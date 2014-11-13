#version 330
#include "electron.fsh"
#include "lighting.fsh"
#include "lightingMath.fsh"

uniform PointLight pointLight;

void main()
{
	vec3 worldToLight = pointLight.position - worldPosition;
	finalColor = calculatePointLight(worldToLight,pointLight.attenuation,pointLight.light.color);
}




