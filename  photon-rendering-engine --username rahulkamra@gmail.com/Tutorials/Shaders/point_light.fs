#version 330
#include "electron.fsh"
#include "lighting.fsh"
#include "lightingMath.fsh"

uniform PointLight pointLight;

void main()
{
	//light vector is opposite to the light direction
	vec3 lightVector = normalize(pointLight.position - worldPosition);
	finalColor = vec4(calculateLight(lightVector,worldNormal,worldPosition,pointLight.light),0);
}
