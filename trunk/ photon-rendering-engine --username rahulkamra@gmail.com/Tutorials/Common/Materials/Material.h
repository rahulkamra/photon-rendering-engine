#pragma once
#include <iostream>
#include <map>
#include <Common\GameObj\Transform.h>

class Shader;
class Texture;
class Material
{
private:
	std::map<std::string, float> floatMap;
	std::map<std::string, glm::vec3> vec3Map;

	void addFloat(std::string name , float value);
	void addVec3(std::string name, glm::vec3 value);
	

protected :
	void AddTexture(const std::string& name, Texture* value);

public:
	Material();
	~Material();

	float getFloat(std::string name);
	glm::vec3 getVec3(std::string name);


	std::map<std::string, Texture*> m_textureMap;
	Texture* GetTexture(const std::string& name);

	Shader* shader;
	virtual void updateUniforms(Transform transform, Shader* shader);
	virtual void bind();

};


