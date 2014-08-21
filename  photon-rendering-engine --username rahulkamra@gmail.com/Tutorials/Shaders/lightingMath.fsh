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


vec3 calculateLight(vec3 lightVector , vec3 worldNormal , vec3 worldPosition , BaseLight baseLight)
{
	float diffuseIntensity  = dot(worldNormal,lightVector);
	if( diffuseIntensity < 0)
		 diffuseIntensity = 0;

	return vec3(diffuseIntensity,diffuseIntensity,diffuseIntensity)*baseLight.color;	
};
