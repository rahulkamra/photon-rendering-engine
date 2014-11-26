#pragma once
#include <iostream>
#include <map>
#include <Common\GameObj\Transform.h>

class Shader;
class Texture;
class Material
{
private:
	
public:
	Material();
	~Material();


	std::map<std::string, Texture*> m_textureMap;
	void AddTexture(const std::string& name, Texture* value);
	Texture* GetTexture(const std::string& name);

	Shader* shader;
	virtual void updateUniforms(Transform transform, Shader* shader);
	virtual void bind();

};


