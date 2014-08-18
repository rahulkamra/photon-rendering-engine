#include "electron.vsh"

out  vec3  worldNormal;
out  vec3  worldPosition;

void initWorldVectors()
{
	worldNormal = normalize(vec3(modelToWorld * vec4(normal , 0.0)));
	worldPosition = vec3(modelToWorld * vec4(position , 1.0));
}


void main()
{
	initWorldVectors();
	vec4 v = vec4(position ,1.0);
    gl_Position = mvp*v;
	color =  inColor;

}