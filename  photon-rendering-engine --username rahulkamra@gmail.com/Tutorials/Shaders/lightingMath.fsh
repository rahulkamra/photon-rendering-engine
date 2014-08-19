struct BaseLight
{
	vec3 color;
};


struct DirectionalLight
{
	BaseLight light;
	vec3 direction;
};


struct PointLight
{
	BaseLight light;
	vec3 position;
};


vec3 calculateLight(vec3 lightVector , vec3 worldNormal , vec3 worldPosition)
{
	float intensity  = dot(worldNormal,lightVector);
	return vec3(intensity*0.7,intensity*0.7,intensity*0.7);	
};
