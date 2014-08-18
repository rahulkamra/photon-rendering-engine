#version 330

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 InColor;
layout (location = 2) in vec3 normal;

uniform vec3 redColor;
uniform  mat4  worldToView;
uniform  mat4  modelToWorld;

uniform  vec4   ambientLight;
uniform  vec3   directionalLight;
uniform  vec3   cameraWorld;

out vec4 Color;

void main()
{
	vec4 v = vec4(Position ,1.0);
	vec4 normalVec4 = vec4(normal , 0);
    gl_Position = worldToView*v;
	vec3 worldCoordinates =  vec3(modelToWorld*v);
	vec3 worldNormal =   normalize(vec3(modelToWorld*normalVec4));
	vec3 lightVector =  normalize(directionalLight - worldCoordinates);
	vec3 eyeVector = normalize(cameraWorld - worldCoordinates);


	float diffuseIntensity = dot(lightVector,worldNormal);
	vec4 diffuseLight = vec4(diffuseIntensity,diffuseIntensity,diffuseIntensity,1.0);

	vec3 reflectedLight  = reflect(- lightVector,worldNormal);
	float speculatIntensity  = dot(reflectedLight,eyeVector);
	speculatIntensity = pow(speculatIntensity,16);
	vec4 specularLight = vec4(speculatIntensity,speculatIntensity,speculatIntensity,1.0);

	Color = clamp(diffuseLight,0,1) +  clamp(specularLight,0,1) +  ambientLight;
}