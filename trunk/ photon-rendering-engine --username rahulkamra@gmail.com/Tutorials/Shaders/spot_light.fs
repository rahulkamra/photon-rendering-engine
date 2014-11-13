#version 330
#include "electron.fsh"
#include "lighting.fsh"
#include "lightingMath.fsh"

uniform SpotLight spotLight;



void main()
{

	vec3 worldToLight = spotLight.position - worldPosition;
	finalColor = calculateSpotLight(worldToLight,spotLight.attenuation,spotLight.light.color,spotLight.direction,spotLight.cutoff);
}




