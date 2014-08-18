#pragma once
#include "Common\Renderer\NormalsRenderer.h"
#include "Utils\ColorUtils.h"
#include <vector>



class BasicMeshRenderer;
class BaseLight;
class Electron
{

private:
	//

public:
	static glm::vec3 ambientLight;

	static vector<BaseLight*> lights;

	static vector<GameObj*> gameObjs;
	static GameObj* root;
	static BaseLight* activeLight;

	static void init();
	static void render();
	static void add(GameObj* gameObj);
	static void addLightsAttrib();
	static void addLight(BaseLight* light);
	
};
