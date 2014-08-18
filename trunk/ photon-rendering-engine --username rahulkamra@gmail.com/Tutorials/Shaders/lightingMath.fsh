struct BaseLight
{
	vec3 color;
};


struct DirectionalLight
{
	BaseLight light;
	vec3 direction;
};


vec3 calculateLight(vec3 worldLightDirection , vec3 worldNormal , vec3 worldPosition)
{
	worldLightDirection = normalize(worldLightDirection);
	float intensity  = dot(worldNormal,-worldLightDirection);
	return vec3(intensity,intensity,intensity);	
};
