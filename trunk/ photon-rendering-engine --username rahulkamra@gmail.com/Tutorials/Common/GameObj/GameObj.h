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


	GameObj()
	{
		
	}


	void drawNormals()
	{
		//normalsShape = ShapeGenerator::generateNormals(shape);
		//DebugUtils::showNormals(this);
	}

	void addChild(GameObj* gameObj);
	void render();
	void addComponent(GameComponent* gameComponent);

};