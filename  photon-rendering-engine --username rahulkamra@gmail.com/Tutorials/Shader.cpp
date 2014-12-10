#include "Shader.h"
#include <Common\Materials\ShaderLoader.h>
#include <Common\Materials\MaterialsList.h>
#include <Camera.h>
#include <Electron.h>
#include <Common\Lights\Lights.h>
#include <Utils\StringUtils.h>

Shader::Shader(std::string fileName)
{
	shaderData = ShaderLoader::getMaterial(fileName);
}


Shader::~Shader()
{
}


void Shader::addTexture(std::string name, Texture* texture)
{
	GLint location = glGetUniformLocation(shaderData->shaderProgram, name.c_str());
	texture->bind(location);
}
void Shader::addMat4(std::string name, glm::mat4 matrix)
{
	GLint location = glGetUniformLocation(shaderData->shaderProgram, name.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
}
void Shader::addVec3(std::string name, glm::vec3 vector)
{
	GLuint location = glGetUniformLocation(shaderData->shaderProgram, name.c_str());
	glUniform3fv(location, 1, &vector[0]);
}
void Shader::addFloat(std::string name, float value)
{
	GLuint location = glGetUniformLocation(shaderData->shaderProgram, name.c_str());
	glUniform1f(location, value);
}

void Shader::updateObjectUniforms(Material* material, Transform* transform)
{

	for (int count = 0; count < shaderData->uniforms.size(); count ++)
	{
		cout << count << shaderData->uniforms.size();
		std::string eachUniform = shaderData->uniforms[count];
		int eachUniformType = shaderData->getUniformType(eachUniform);

		if (eachUniform == "diffuse")
		{
			cout << material->GetTexture("diffuse");
			this->addTexture("diffuse",material->GetTexture("diffuse"));
		}
		else if (eachUniform == "mvp")
		{
			glm::mat4 modelViewProjection = Camera::getCamera()->worldToProjection(transform->modelTransformtionMatrix());
			this->addMat4("mvp", modelViewProjection);
		}
		else if (eachUniform == "modelToWorld")
		{
			glm::mat4 model = transform->modelTransformtionMatrix();
			this->addMat4("modelToWorld", model);
		}
		else if (eachUniform == "ambientLight")
		{
			this->addVec3("ambientLight", Electron::ambientLight);
		}
		else if (eachUniform == "cameraWorld")
		{
			this->addVec3("cameraWorld", Camera::getCamera()->transform.getPosition());
		}
		else if (StringUtils::startsWith(eachUniform,"pointLight"))
		{
			updatePointLightUniform((PointLight*)Electron::activeLight);
		}
		else if (StringUtils::startsWith(eachUniform, "directionalLight"))
		{
			updateDirectionalLightUniform((DirectionalLight*)Electron::activeLight);
		}
		else if (StringUtils::startsWith(eachUniform, "spotLight"))
		{
			updateSpotLightUniform((SpotLight*)Electron::activeLight);
		}
		else
		{
			addMaterialUniforms(material, eachUniform, eachUniformType);
			cout << "Cannot  Update Uniform " << eachUniform << "\n";
		}
	}
}

void Shader::addMaterialUniforms(Material* material,std::string name, int type)
{
	switch (type)
	{

	case GL_FLOAT:
	{
		float floatVal = material->getFloat(name);
		this->addFloat(name, floatVal);
		break;
	}

	case GL_FLOAT_VEC3:
	{
		glm::vec3 vec3Val = material->getVec3(name);
		this->addVec3(name, vec3Val);
		break;
	}

	default:
	{

		break;
	}
		
	}
}

void Shader::updatePointLightUniform(PointLight* pointLight)
{
	this->addVec3("pointLight.position", pointLight->getParent()->transform.getPosition());
	this->addVec3("pointLight.light.color", pointLight->color);

	this->addFloat("pointLight.attenuation.constant", pointLight->attenuation.constant);
	this->addFloat("pointLight.attenuation.linear", pointLight->attenuation.linear);
	this->addFloat("pointLight.attenuation.quadratic", pointLight->attenuation.quadratic);

	this->addFloat("pointLight.range", pointLight->range);
}


void Shader::updateSpotLightUniform(SpotLight* pointLight)
{
	this->addVec3("spotLight.position", pointLight->getParent()->transform.getPosition());
	this->addVec3("spotLight.light.color", pointLight->color);

	this->addFloat("spotLight.attenuation.constant", pointLight->attenuation.constant);
	this->addFloat("spotLight.attenuation.linear", pointLight->attenuation.linear);
	this->addFloat("spotLight.attenuation.quadratic", pointLight->attenuation.quadratic);


	this->addVec3("spotLight.direction", pointLight->getParent()->transform.forward());

	this->addFloat("spotLight.cutoff", pointLight->cutoff);

	this->addFloat("spotLight.range", pointLight->range);
}
void Shader::updateDirectionalLightUniform(DirectionalLight* pointLight)
{
	this->addVec3("directionalLight.direction", pointLight->getParent()->transform.forward());
	this->addVec3("directionalLight.light.color", pointLight->color);
}



void Shader::bind()
{
	glUseProgram(shaderData->shaderProgram);
}