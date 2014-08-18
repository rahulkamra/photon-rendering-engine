#pragma once

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <Electron_std.h>
#include "Common\Geometry\MeshData.h"
#include "Common\Geometry\Mesh.h"
#include "Common\ShapeGenerator.h"
#include "Common\Debug\DebugUtils.h"
#include "Common\Materials\MaterialsList.h"
#include "Transform.h"
#include <vector>
using namespace glm;
class GameComponent;

class GameObj
{
	private:
	void renderGameObj();

	public:
	glm::vec3 translation;
	Transform transform;
	vector<GameObj*> children;
	vector<GameComponent*> components;
	

	void addChild(GameObj* gameObj);
	void render();
	void addedToStage();
	void addComponent(GameComponent* gameComponent);

	void _callAddedToStage();
};