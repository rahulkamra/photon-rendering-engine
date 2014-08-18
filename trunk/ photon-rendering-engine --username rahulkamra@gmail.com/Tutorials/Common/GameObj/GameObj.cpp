#include "GameObj.h"
#include "GameComponent.h"

void GameObj::addChild(GameObj* gameObj)
{
	children.push_back(gameObj);
	gameObj->_callAddedToStage();
}

void GameObj::_callAddedToStage()
{
	this->addedToStage();

	for (int count = 0; count < components.size(); count++)
	{
		GameComponent* gameComponent = components.at(count);
		gameComponent->addedToStage();
	}

	for (int count = 0; count < children.size(); count++)
	{
		GameObj* childObj = children.at(count);
		childObj->_callAddedToStage();
	}
}


void GameObj::addedToStage()
{

}

void GameObj::addComponent(GameComponent* gameComponent)
{
	gameComponent->setParent(this);
	components.push_back(gameComponent);
	gameComponent->addedToGameObj();
}
void GameObj::render()
{
	renderGameObj();
	for (int count = 0; count < children.size(); count++)
	{
		GameObj* gameObj = children.at(count);
		gameObj->render();
	}
}


void GameObj::renderGameObj()
{
	for (int count = 0; count < components.size(); count++)
	{
		GameComponent* gameComponent = components.at(count);
		gameComponent->render();
	}

	
}