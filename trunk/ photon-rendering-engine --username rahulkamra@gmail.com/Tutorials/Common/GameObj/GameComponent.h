#pragma once

class GameObj;
class GameComponent
{

protected:
	GameObj* parent;
public:
	GameComponent();
	~GameComponent();

	void setParent(GameObj* gameObj);
	GameObj* getParent();
	virtual void render(){}
	virtual void addedToGameObj(){}
	virtual void addedToStage(){}

 
};

