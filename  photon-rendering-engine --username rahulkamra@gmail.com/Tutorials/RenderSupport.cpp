#include "RenderSupport.h"


RenderSupport::RenderSupport()
{
}


RenderSupport::~RenderSupport()
{

}


void RenderSupport::useShader(Shader* shader)
{
	bool useShader = false;
	if (!isShaderValid(currentShader))
	{
		if (isShaderValid(shader))
			useShader = true;
	}


	if (isShaderValid(currentShader) && isShaderValid(shader))
	{
		if (currentShader->getShaderData()->shaderProgram != shader-> getShaderData()->shaderProgram)
		{
			useShader = true;
		}
	}

	if (useShader)
	{
		glUseProgram(shader->getShaderData()->shaderProgram);
		currentShader = shader;
	}


}


bool inline RenderSupport::isShaderValid(Shader* shader)
{
	return shader != nullptr && shader->getShaderData() != nullptr;

}