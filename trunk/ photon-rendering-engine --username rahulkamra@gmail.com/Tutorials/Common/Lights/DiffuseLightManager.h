#pragma once
#include <glm\glm.hpp>
#include <vector>
#include <Electron.h>
#include <Common\Geometry\Premitives\Premitives.h>

using namespace glm;
using namespace std;
class DiffuseLightManager
{
	
	static vector<vec3> lights;
public:
	static void addLight(vec3 lightSource, bool showGadget)
	{
		lights.push_back(lightSource);
		if (showGadget)
		{
			//Cube* gadget = new Cube();
			//gadget->translate(lightSource);
			//gadget->scale(vec3(0.05f, 0.05f, 0.05f));
			//Electron::add(gadget);
		}
	}


	static void addAttribs(GLuint shaderId)
	{
		//if (Electron::lights.size() > 0)
		//{
			//vec3 light = Electron::lights.at(0);
		//	GLuint directionalLightUniformLocation = glGetUniformLocation(shaderId, "directionalLight");
			//glUniform3fv(directionalLightUniformLocation, 1, &light[0]);
		//}
	}
	
};