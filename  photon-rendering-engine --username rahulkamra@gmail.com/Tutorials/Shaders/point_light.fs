#version 330
#include "electron.fsh"
#include "lighting.fsh"
#include "lightingMath.fsh"

uniform PointLight pointLight;



vec4 calculatePointLight()
{
	vec3 lightVector = pointLight.position - worldPosition;
	float distance = length(lightVector);
	vec3 normalizedVector = normalize(lightVector);

	float attenuation = pointLight.attenuation.constant +
                         pointLight.attenuation.linear * distance +
                         pointLight.attenuation.quadratic * distance * distance;
                         

	vec4 lightColor = vec4(calculateLight(normalizedVector,worldNormal,worldPosition,pointLight.light),0);

	return lightColor/ attenuation;
}


void main()
{

	finalColor = calculatePointLight();
}




