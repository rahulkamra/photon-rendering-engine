#include "ETime.h"
#include <SDL.h>

ETime::ETime()
{
}


ETime::~ETime()
{
}

bool ETime::initialize()
{
	lastTickTime =  SDL_GetTicks();
	return true;
}
bool ETime::destroy()
{
	return true;
}

bool ETime::nextFrame()
{
	float currentETime = SDL_GetTicks();
	deltaTime = currentETime - lastTickTime;
	lastTickTime = currentETime;
	return true;
}

