#pragma once
class ETime
{
private :
	float lastTickTime;
public:
	ETime();
	~ETime();

	bool initialize();
	bool destroy();

	bool nextFrame();

	float deltaTime;

};

