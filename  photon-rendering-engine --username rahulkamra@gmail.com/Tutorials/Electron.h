#pragma once
#include <vector>
#include <Common\GameObj\GameObj.h>
#include <RenderSupport.h>

class BasicMeshRenderer;
class BaseLight;
class MeshRenderingComponent;

class Electron
{

private:
	static void drawPhase(vector<MeshRenderingComponent*> renderingComponents, Material* material = nullptr);
	static RenderSupport* renderSupport;

public:

	static const int PHASE_FORWARD_RENDERING;
	static const int PHASE_DEFFERED_RENDERING;
	static const int PHASE_WIDGETS_RENDERING;


	static glm::vec3 ambientLight;

	static vector<BaseLight*> lights;

	static vector<GameObj*> gameObjs;
	static GameObj* root;
	static BaseLight* activeLight;

	static vector<MeshRenderingComponent*> forwardRenderingComponents;
	static vector<MeshRenderingComponent*> deferredRenderingComponents;
	static vector<MeshRenderingComponent*> widgetsRenderingComponents;


	static int currentPhaseRendering;

	static void init();
	static void render();
	static void draw();

	static void add(GameObj* gameObj);
	static void addLight(BaseLight* light);
	static void addRenderingComponent(MeshRenderingComponent* meshRenderingComponent);
};
