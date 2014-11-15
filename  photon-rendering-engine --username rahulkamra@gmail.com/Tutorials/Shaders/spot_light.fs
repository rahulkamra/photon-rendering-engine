#version 330
#include "electron.fsh"
#include "lighting.fsh"
#include "lightingMath.fsh"

uniform SpotLight spotLight;



void main()
{

	vec3 lightVector =  worldPosition-spotLight.position;
	finalColor = calculateSpotLight(lightVector,spotLight.attenuation,spotLight.light.color,spotLight.direction,spotLight.cutoff);
}




