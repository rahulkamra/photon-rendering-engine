#pragma once
#include "Common\GameObj\GameComponent.h"

class BaseLight : public GameComponent
{

public:
	void addedToGameObj();
	void virtual bind();
	GLuint virtual getShaderId(){ return 0; };
	virtual void addedToStage();
	void virtual updateUniforms(Material* material){};
};

class DirectionalLight : public BaseLight
{
public:
	GLuint virtual getShaderId();
	void virtual updateUniforms(Material* material);
};


class PointLight : public BaseLight
{
public:
	GLuint virtual getShaderId();
	void virtual updateUniforms(Material* material);
};


