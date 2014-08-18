#pragma once
#include <glm\glm.hpp>


class ColorUtils
{
public:
	static glm::vec3 randomColor()
	{
		glm::vec3 ret;
		ret.x = rand() / (float)RAND_MAX;
		ret.y = rand() / (float)RAND_MAX;
		ret.z = rand() / (float)RAND_MAX;
		return ret;
	}

};