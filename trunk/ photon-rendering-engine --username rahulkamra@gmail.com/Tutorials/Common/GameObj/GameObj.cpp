#include "GameObj.h"
#include "GameComponent.h"

void GameObj::addChild(GameObj* gameObj)
{
	children.push_back(gameObj);
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