#pragma once
#include <string>
#include <GL\glew.h>
#include <glm\gtc\matrix_transform.hpp>
#include <Common\GameObj\Transform.h>
#include <Texture.h>
#include "ShaderData.h"
#include <Common\Lights\Lights.h>
#include <Common\Materials\Material.h>


class Shader
{

private :
	ShaderData* shaderData;
	void addMaterialUniforms(Material* material,std::string name, int type);

public:
	void addMat4(std::string name, glm::mat4 matrix);
	void addVec3(std::string name, glm::vec3 vector);
	void addFloat(std::string name, float value);
	void addTexture(std::string name, Texture* texture);

	ShaderData* getShaderData();

	void updateObjectUniforms(Material* material, Transform* transform);
	void updatePointLightUniform(PointLight* pointLight);
	void updateSpotLightUniform(SpotLight* pointLight);
	void updateDirectionalLightUniform(DirectionalLight* pointLight);
	void bind();
	
	Shader(std::string fileName);
	~Shader();
};

