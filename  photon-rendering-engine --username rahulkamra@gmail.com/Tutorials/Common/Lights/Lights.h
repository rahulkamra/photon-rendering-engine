#pragma once
#include "Common\GameObj\GameComponent.h"

class BaseLight : public GameComponent
{

public:
	BaseLight();
	~BaseLight();

	void addedToGameObj();
	void virtual bind(){};
	GLuint virtual getShaderId(){ return 0; };
	void virtual updateUniforms(Material* material){};
};

class DirectionalLight : public BaseLight
{
public:
	DirectionalLight();
	~DirectionalLight();
	void virtual bind();
	GLuint virtual getShaderId();
	void virtual updateUniforms(Material* material);
};

