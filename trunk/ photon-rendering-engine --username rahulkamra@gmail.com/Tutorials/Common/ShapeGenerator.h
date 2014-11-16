#pragma once
#include <assimp\Importer.hpp>
#include <assimp\postprocess.h> // Post processing flags
#include <assimp\scene.h>       // Output data structure

#include <vector>
#include <Common\Geometry\MeshData.h>

class ShapeGenerator
{
	static Vertex* makePlaneVerts(int dimensions, glm::vec3 color, bool generateRandomColor);
	static GLushort* makePlaneIndices(int dimensions);
	static GLushort* makePlaneUnseamedIndices(int tesselation);

	// Teapot helpers
	static void generatePatches(float * v, float * n, float * tc, unsigned short* el, int grid);
	static void moveLid(int grid, float *v, glm::mat4 lidTransform);

	static void buildPatchReflect(int patchNum,
		float *B, float *dB,
		float *v, float *n,
		float *tc, unsigned short *el,
		int &index, int &elIndex, int &tcIndex, int grid,
		bool reflectX, bool reflectY);

	static void buildPatch(glm::vec3 patch[][4],
		float *B, float *dB,
		float *v, float *n, float *tc,
		unsigned short *el,
		int &index, int &elIndex, int &tcIndex,
		int grid, glm::mat3 reflect,
		bool invertNormal);

	static void getPatch(int patchNum, glm::vec3 patch[][4], bool reverseV);
	static void computeBasisFunctions(float * B, float * dB, int grid);

	static glm::vec3 evaluate(int gridU, int gridV, float *B, glm::vec3 patch[][4]);
	static glm::vec3 evaluateNormal(int gridU, int gridV,
		float *B, float *dB, glm::vec3 patch[][4]);

	static vector<MeshData*> initFromScene(const aiScene* scene);

public:
	static MeshData* makeTriangle();
	static MeshData* makeCube();
	static MeshData* makeArrow();
	static MeshData* makePlane(uint dimensions = 10, glm::vec3 color = glm::vec3(0.2, 0.2, 0.2), bool generateRandomColor = true);
	static MeshData* makeTeapot(uint tesselation = 10, const glm::mat4& lidTransform = glm::mat4());
	static MeshData* makeSphere(uint tesselation = 20);
	static MeshData* makeTorus(uint tesselation = 20);
	static MeshData generateNormals(const MeshData& data);
	static MeshData* makePyramid();

	static MeshData* createAxis(float length = 1.0f);

	static MeshData* createDirectionalWidget(float radius, int numSegments, int numDirectionalElements, glm::vec3 color = glm::vec3(1,0,0));
	static vector<MeshData*> createShapeFromFile(string  fileName);
};

