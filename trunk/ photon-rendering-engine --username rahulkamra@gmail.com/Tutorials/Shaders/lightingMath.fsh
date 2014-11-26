struct BaseLight
{

	vec3 color;
};

struct Attenuation
{
    float constant;
    float linear;
    float quadratic;
};



struct DirectionalLight
{
	BaseLight light;
	vec3 direction;
};


struct PointLight
{
	BaseLight light;
	Attenuation attenuation;
	vec3 position;
	float range;
};

struct SpotLight
{
	BaseLight light;
	Attenuation attenuation;
	vec3 position;
	float range;
	vec3 direction;
	float cutoff;
};

//Light Direction is from Light to the surface.
vec4 calculateLight(vec3 lightDirection , vec3 worldNormal , vec3 worldPosition , vec3 color)
{
	vec4 specularColor = vec4(0,0,0,0);
	vec4 diffuseColor = vec4(0,0,0,0);

	worldNormal = normalize(worldNormal); //need to check are we renormalizing it or not

	float diffuseIntensity  = dot(worldNormal,-lightDirection);
	diffuseIntensity = clamp(diffuseIntensity,0,1);
	
	diffuseColor = vec4(diffuseIntensity,diffuseIntensity,diffuseIntensity,1.0)*vec4(color,1.0);

    vec3 eyeVector = normalize(cameraWorld - worldPosition);
	vec3 reflectVector = reflect(lightDirection,worldNormal);


	//vec3 hanfAngleDirection = normalize(eyeVector - lightDirection);
	//float specularFactor = dot(hanfAngleDirection, worldNormal);

	
	float specularFactor = dot(reflectVector,eyeVector);
	specularFactor = pow(specularFactor, specularPower);
	 if(specularFactor > 0 )
	 {
		 specularColor = vec4(color, 1.0) *  specularFactor * specularIntensity;
	 }
	 return  diffuseColor + specularColor;
	
};


vec4 calculatePointLight(vec3 lightVector,Attenuation attenuation,vec3 color)
{
	float distance = length(lightVector);
	vec3 normalizedVector = normalize(lightVector);

	float attenuationValue = attenuation.constant +
                         attenuation.linear * distance +
                         attenuation.quadratic * distance * distance;
                         

	vec4 lightColor = calculateLight(normalizedVector,worldNormal,worldPosition,color);

	return lightColor/ attenuationValue;
}

vec4 calculateSpotLight(vec3 lightVector,Attenuation attenuation,vec3 color,vec3 direction,float cutoff)
{
	vec3 normalizeLightVector = normalize(lightVector);
	float spotFactor = dot(normalizeLightVector,normalize(direction));
	if(spotFactor > cutoff)
	{
		vec4 pointColor = calculatePointLight(normalizeLightVector,attenuation,color);
		return pointColor*(1.0-(1.0 - spotFactor)*1.0/(1.0 - cutoff));
	}
	else
	{
		return vec4(0,0,0,0);
	}
}