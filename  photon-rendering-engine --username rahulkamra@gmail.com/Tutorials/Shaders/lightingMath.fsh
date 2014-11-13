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


vec3 calculateLight(vec3 lightVector , vec3 worldNormal , vec3 worldPosition , vec3 color)
{
	float diffuseIntensity  = dot(worldNormal,lightVector);
	if( diffuseIntensity < 0)
		 diffuseIntensity = 0;

	return vec3(diffuseIntensity,diffuseIntensity,diffuseIntensity)*color;	
};


vec4 calculatePointLight(vec3 worldToLight,Attenuation attenuation,vec3 color)
{
	float distance = length(worldToLight);
	vec3 normalizedVector = normalize(worldToLight);

	float attenuationValue = attenuation.constant +
                         attenuation.linear * distance +
                         attenuation.quadratic * distance * distance;
                         

	vec4 lightColor = vec4(calculateLight(normalizedVector,worldNormal,worldPosition,color),0);

	return lightColor/ attenuationValue;
}

vec4 calculateSpotLight(vec3 worldToLight,Attenuation attenuation,vec3 color,vec3 direction,float cutoff)
{
	vec3 lightToWorld = normalize(-worldToLight);
	float spotFactor = dot(lightToWorld,direction);
	if(spotFactor > cutoff)
	{
		vec4 pointColor = calculatePointLight(-worldToLight,attenuation,color);
		//return pointColor;
		return pointColor*(1.0-(1.0 - spotFactor)*1.0/(1.0 - cutoff));
	}
	else
	{
		return vec4(0,0,0,0);
	}
}