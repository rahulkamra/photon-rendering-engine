#pragma once
#include <Shader.h>

class RenderSupport
{
private:
	Shader* currentShader;
	bool inline isShaderValid(Shader* shader);

public:
	RenderSupport();
	~RenderSupport();

	void useShader(Shader* shader);

};

