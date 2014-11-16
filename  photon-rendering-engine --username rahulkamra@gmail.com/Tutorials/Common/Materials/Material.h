#pragma once
#include <iostream>
#include <GL\glew.h>
#include <glm\gtc\matrix_transform.hpp>
#include <Common\GameObj\Transform.h>
#include <Texture.h>

class Material
{
public:
	Material();
	~Material();

	void inline addMat4(std::string name, glm::mat4 matrix);
	void inline addVec3(std::string name, glm::vec3 vector);
	void  addFloat(std::string name, float value);
	GLuint virtual inline getShaderId();
	void virtual addUniforms(Transform transform);
	void inline addTextureUniform(std::string name, GLuint samplerId);
	virtual void bind();

	std::map<std::string, Texture*> m_textureMap;

	inline void AddTexture(const std::string& name, Texture* value) 
	{
		m_textureMap.insert(std::pair<std::string, Texture*>(name, value)); 
	}

	inline Texture* GetTexture(const std::string& name) const
	{
		std::map<std::string, Texture*>::const_iterator it = m_textureMap.find(name);
		if (it != m_textureMap.end())
			return it->second;

		return 0;
	}
};


class BasicMaterial : public Material
{
public:

};


class AmbientMaterial : public Material
{
public:
	AmbientMaterial();
	AmbientMaterial(Texture* diffuseTexture);
	void virtual addUniforms(Transform transform);

};

