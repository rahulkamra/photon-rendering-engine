#include "GameComponent.h"


GameComponent::GameComponent()
{
}


GameComponent::~GameComponent()
{
}


void GameComponent::setParent(GameObj* gameObj)
{
	this->parent = gameObj;
}

