#pragma once
#include "ShapeGenerator.h"
#include "Common\Geometry\MeshData.h"
#include <Utils\ColorUtils.h>
#include <glm\gtc\matrix_transform.hpp>
#include <iostream>
#include <math.h>
#define PI 3.14159265359

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a)

using glm::vec3;
using glm::vec2;
using glm::mat4;
using glm::mat3;


MeshData* ShapeGenerator::makeTriangle()
{
	//MeshData ret;

	Vertex myTri[] =
	{
		vec3(+0.0f, +1.0f, +0.0f),
		vec3(+1.0f, +0.0f, +0.0f),
		vec3(+0.0f, +0.0f, +1.0f),
		vec2(0.0f,0.1f),

		vec3(-1.0f, -1.0f, +0.0f),
		vec3(+0.0f, +1.0f, +0.0f),
		vec3(+0.0f, +0.0f, +1.0f),
		vec2(0.0f, 0.1f),

		vec3(+1.0f, -1.0f, +0.0f),
		vec3(+0.0f, +0.0f, +1.0f),
		vec3(+0.0f, +0.0f, +1.0f),
		vec2(0.0f, 0.1f)
	};
	//ret.numVertices = NUM_ARRAY_ELEMENTS(myTri);
	//ret.vertices = new Vertex[ret.numVertices];
	//memcpy(ret.vertices, myTri, sizeof(myTri));

	//GLushort indices[] = { 0, 1, 2 };
	//ret.numIndices = NUM_ARRAY_ELEMENTS(indices);
	//ret.indices = new GLushort[ret.numIndices];
	//memcpy(ret.indices, indices, sizeof(indices));

	//return ret;
	return NULL;
}



MeshData* ShapeGenerator::makeCube()
{
	//MeshData ret;

	GLuint numVertices = 24;
	Vertex* vertex = new Vertex[numVertices];

	vertex[0].position = vec3(-1.0f, +1.0f, +1.0f);  // 0
	vertex[0].color = vec3(+1.0f, +0.0f, +0.0f);	// Color
	vertex[0].normal = vec3(+0.0f, +1.0f, +0.0f);  // Normal

	vertex[1].position = vec3(+1.0f, +1.0f, +1.0f);  // 1
	vertex[1].color = vec3(+0.0f, +1.0f, +0.0f);	// Color
	vertex[1].normal = vec3(+0.0f, +1.0f, +0.0f);  // Normal

	vertex[2].position = vec3(+1.0f, +1.0f, -1.0f);  // 2
	vertex[2].color = vec3(+0.0f, +0.0f, +1.0f);  // Color
	vertex[2].normal = vec3(+0.0f, +1.0f, +0.0f);  // Normal

	vertex[3].position = vec3(-1.0f, +1.0f, -1.0f);  // 3
	vertex[3].color = vec3(+1.0f, +1.0f, +1.0f);  // Color
	vertex[3].normal = vec3(+0.0f, +1.0f, +0.0f);  // Normal

	vertex[4].position = vec3(-1.0f, +1.0f, -1.0f);  // 4
	vertex[4].color = vec3(+1.0f, +0.0f, +1.0f);  // Color
	vertex[4].normal = vec3(+0.0f, +0.0f, -1.0f);  // Normal

	vertex[5].position = vec3(+1.0f, +1.0f, -1.0f);  // 5
	vertex[5].color = vec3(+0.0f, +0.5f, +0.2f);  // Color
	vertex[5].normal = vec3(+0.0f, +0.0f, -1.0f);  // Normal

	vertex[6].position = vec3(+1.0f, -1.0f, -1.0f);  // 6
	vertex[6].color = vec3(+0.8f, +0.6f, +0.4f);  // Color
	vertex[6].normal = vec3(+0.0f, +0.0f, -1.0f);  // Normal

	vertex[7].position = vec3(-1.0f, -1.0f, -1.0f);  // 7
	vertex[7].color = vec3(+0.3f, +1.0f, +0.5f);  // Color
	vertex[7].normal = vec3(+0.0f, +0.0f, -1.0f);  // Normal

	vertex[8].position = vec3(+1.0f, +1.0f, -1.0f);  // 8
	vertex[8].color = vec3(+0.2f, +0.5f, +0.2f);  // Color
	vertex[8].normal = vec3(+1.0f, +0.0f, +0.0f);  // Normal

	vertex[9].position = vec3(+1.0f, +1.0f, +1.0f);  // 9
	vertex[9].color = vec3(+0.9f, +0.3f, +0.7f);  // Color
	vertex[9].normal = vec3(+1.0f, +0.0f, +0.0f);  // Normal

	vertex[10].position = vec3(+1.0f, -1.0f, +1.0f);  // 10
	vertex[10].color = vec3(+0.3f, +0.7f, +0.5f);  // Color
	vertex[10].normal = vec3(+1.0f, +0.0f, +0.0f);  // Normal

	vertex[11].position = vec3(+1.0f, -1.0f, -1.0f);  // 11
	vertex[11].color = vec3(+0.5f, +0.7f, +0.5f);  // Color
	vertex[11].normal = vec3(+1.0f, +0.0f, +0.0f);  // Normal


	vertex[12].position = vec3(-1.0f, +1.0f, +1.0f);  // 12
	vertex[12].color = vec3(+0.7f, +0.8f, +0.2f);  // Color
	vertex[12].normal = vec3(-1.0f, +0.0f, +0.0f);  // Normal

	vertex[13].position = vec3(-1.0f, +1.0f, -1.0f);  // 13
	vertex[13].color = vec3(+0.5f, +0.7f, +0.3f);  // Color
	vertex[13].normal = vec3(-1.0f, +0.0f, +0.0f);  // Normal

	vertex[14].position = vec3(-1.0f, -1.0f, -1.0f);  // 14
	vertex[14].color = vec3(+0.4f, +0.7f, +0.7f);  // Color
	vertex[14].normal = vec3(-1.0f, +0.0f, +0.0f);  // Normal

	vertex[15].position = vec3(-1.0f, -1.0f, +1.0f);  // 15
	vertex[15].color = vec3(+0.2f, +0.5f, +1.0f);  // Color
	vertex[15].normal = vec3(-1.0f, +0.0f, +0.0f);  // Normal

	vertex[16].position = vec3(+1.0f, +1.0f, +1.0f);  // 16
	vertex[16].color = vec3(+0.6f, +1.0f, +0.7f);  // Color
	vertex[16].normal = vec3(+0.0f, +0.0f, +1.0f);  // Normal

	vertex[17].position = vec3(-1.0f, +1.0f, +1.0f);  // 17
	vertex[17].color = vec3(+0.6f, +0.4f, +0.8f);  // Color
	vertex[17].normal = vec3(+0.0f, +0.0f, +1.0f);  // Normal

	vertex[18].position = vec3(-1.0f, -1.0f, +1.0f);  // 18
	vertex[18].color = vec3(+0.2f, +0.8f, +0.7f);  // Color
	vertex[18].normal = vec3(+0.0f, +0.0f, +1.0f);  // Normal

	vertex[19].position = vec3(+1.0f, -1.0f, +1.0f);  // 19
	vertex[19].color = vec3(+0.2f, +0.7f, +1.0f);  // Color
	vertex[19].normal = vec3(+0.0f, +0.0f, +1.0f);  // Normal

	vertex[20].position = vec3(+1.0f, -1.0f, -1.0f);  // 20
	vertex[20].color = vec3(+0.8f, +0.3f, +0.7f);  // Color
	vertex[20].normal = vec3(+0.0f, -1.0f, +0.0f);  // Normal

	vertex[21].position = vec3(-1.0f, -1.0f, -1.0f);  // 21
	vertex[21].color = vec3(+0.8f, +0.9f, +0.5f);  // Color
	vertex[21].normal = vec3(+0.0f, -1.0f, +0.0f);  // Normal

	vertex[22].position = vec3(-1.0f, -1.0f, +1.0f);  // 22
	vertex[22].color =    vec3(+0.5f, +0.8f, +0.5f);  // Color
	vertex[22].normal =   vec3(+0.0f, -1.0f, +0.0f);  // Normal

	vertex[23].position = vec3(+1.0f, -1.0f, +1.0f);  // 23
	vertex[23].color = vec3(+0.9f, +1.0f, +0.2f);  // Color
	vertex[23].normal = vec3(+0.0f, -1.0f, +0.0f);  // Normal


	GLuint numIndices = 36;
	GLushort* indices = new GLushort[numIndices];
	
		
	indices[0] = 0; indices[1] = 1; indices[2] = 2; indices[3] = 0; indices[4] = 2; indices[5] = 3; // Top
	indices[6] = 4; indices[7] = 5; indices[8] = 6; indices[9] = 4; indices[10] = 6; indices[11] = 7; // Front
	indices[12] = 8; indices[13] = 9; indices[14] = 10; indices[15] = 8; indices[16] = 10; indices[17] = 11; // Right 
	indices[18] = 12; indices[19] = 13; indices[20] = 14; indices[21] = 12; indices[22] = 14; indices[23] = 15; // Left
	indices[24] = 16; indices[25] = 17; indices[26] = 18; indices[27] = 16; indices[28] = 18; indices[29] = 19; // Back
	indices[30] = 20; indices[31] = 22; indices[32] = 21; indices[33] = 20; indices[34] = 23; indices[35] = 22; // Bottom

	MeshData* meshdata = new MeshData(vertex,numVertices,indices,numIndices);
	return meshdata;
}



MeshData* ShapeGenerator::makeArrow()
{
	//MeshData ret;
	GLuint numVertices = 40;
	Vertex* vertex = new Vertex[numVertices];

	vertex[0].position = vec3(+0.00f, +0.25f, -0.25f);         // 0
	vertex[0].color = vec3(+1.00f, +0.00f, +0.00f);		  // Color
	vertex[0].normal = vec3(+0.00f, +1.00f, +0.00f);         // Normal

	vertex[1].position =  vec3(+0.50f, +0.25f, -0.25f);         // 1
	vertex[1].color =     vec3(+1.00f, +0.00f, +0.00f);		  // Color
	vertex[1].normal =    vec3(+0.00f, +1.00f, +0.00f);         // Normal

	vertex[2].position = vec3(+0.00f, +0.25f, -1.00f);         // 2
	vertex[2].color = vec3(+1.00f, +0.00f, +0.00f);		  // Color
	vertex[2].normal = vec3(+0.00f, +1.00f, +0.00f);         // Normal


	vertex[3].position = vec3(-0.50f, +0.25f, -0.25f);         // 3
	vertex[3].color = vec3(+1.00f, +0.00f, +0.00f);		  // Color
	vertex[3].normal = vec3(+0.00f, +1.00f, +0.00f);         // Normal


	// Bottom side of arrow head
	vertex[4].position = vec3(+0.00f, -0.25f, -0.25f);         // 4
	vertex[4].color = vec3(+0.00f, +0.00f, +1.00f);		  // Color
	vertex[4].normal = vec3(+0.00f, -1.00f, +0.00f);         // Normal


	vertex[5].position = vec3(+0.50f, -0.25f, -0.25f);         // 5
	vertex[5].color = vec3(+0.00f, +0.00f, +1.00f);		  // Color
	vertex[5].normal = vec3(+0.00f, -1.00f, +0.00f);         // Normal


	vertex[6].position = vec3(+0.00f, -0.25f, -1.00f);         // 6
	vertex[6].color = vec3(+0.00f, +0.00f, +1.00f);		  // Color
	vertex[6].normal = vec3(+0.00f, -1.00f, +0.00f);         // Normal


	vertex[7].position = vec3(-0.50f, -0.25f, -0.25f);         // 7
	vertex[7].color = vec3(+0.00f, +0.00f, +1.00f);		  // Color
	vertex[7].normal = vec3(+0.00f, -1.00f, +0.00f);         // Normal

	// Right side of arrow tip
	vertex[8].position = vec3(+0.50f, +0.25f, -0.25f);         // 8
	vertex[8].color = vec3(+0.60f, +1.00f, +0.00f);		  // Color
	vertex[8].normal = vec3(0.83205032f, 0.00f, -0.55470026f); // Normal


	vertex[9].position = vec3(+0.00f, +0.25f, -1.00f);         // 9
	vertex[9].color = vec3(+0.60f, +1.00f, +0.00f);		  // Color
	vertex[9].normal = vec3(0.83205032f, 0.00f, -0.55470026f); // Normal


	vertex[10].position = vec3(+0.00f, -0.25f, -1.00f);         // 10
	vertex[10].color = vec3(+0.60f, +1.00f, +0.00f);		  // Color
	vertex[10].normal = vec3(0.83205032f, 0.00f, -0.55470026f); // Normal


	vertex[11].position = vec3(+0.50f, -0.25f, -0.25f);         // 11
	vertex[11].color = vec3(+0.60f, +1.00f, +0.00f);		  // Color
	vertex[11].normal = vec3(0.83205032f, 0.00f, -0.55470026f); // Normal


	// Left side of arrow tip
	vertex[12].position = vec3(+0.00f, +0.25f, -1.00f);         // 12
	vertex[12].color = vec3(+0.00f, +1.00f, +0.00f);		  // Color
	vertex[12].normal = vec3(-0.55708605f, 0.00f, -0.37139067f); // Normal


	vertex[13].position = vec3(-0.50f, +0.25f, -0.25f);         // 13
	vertex[13].color = vec3(+0.00f, +1.00f, +0.00f);		  // Color
	vertex[13].normal = vec3(-0.55708605f, 0.00f, -0.37139067f); // Normal


	vertex[14].position = vec3(+0.00f, -0.25f, -1.00f);         // 14
	vertex[14].color = vec3(+0.00f, +1.00f, +0.00f);		  // Color
	vertex[14].normal = vec3(-0.55708605f, 0.00f, -0.37139067f); // Normal


	vertex[15].position = vec3(-0.50f, -0.25f, -0.25f);         // 15
	vertex[15].color = vec3(+0.00f, +1.00f, +0.00f);		  // Color
	vertex[15].normal = vec3(-0.55708605f, 0.00f, -0.37139067f); // Normal


	// Back side of arrow tip
	vertex[16].position = vec3(-0.50f, +0.25f, -0.25f);         // 16
	vertex[16].color = vec3(+0.50f, +0.50f, +0.50f);		  // Color
	vertex[16].normal = vec3(+0.00f, +0.00f, +1.00f);         // Normal


	vertex[17].position = vec3(+0.50f, +0.25f, -0.25f);         // 17
	vertex[17].color = vec3(+0.50f, +0.50f, +0.50f);		  // Color
	vertex[17].normal = vec3(+0.00f, +0.00f, +1.00f);         // Normal


	vertex[18].position = vec3(-0.50f, -0.25f, -0.25f);         // 18
	vertex[18].color = vec3(+0.50f, +0.50f, +0.50f);		  // Color
	vertex[18].normal = vec3(+0.00f, +0.00f, +1.00f);         // Normal


	vertex[19].position = vec3(+0.50f, -0.25f, -0.25f);         // 19
	vertex[19].color = vec3(+0.50f, +0.50f, +0.50f);		  // Color
	vertex[19].normal = vec3(+0.00f, +0.00f, +1.00f);         // Normal


	// Top side of back of arrow
	vertex[20].position = vec3(+0.25f, +0.25f, -0.25f);         // 20
	vertex[20].color = vec3(+1.00f, +0.00f, +0.00f);		  // Color
	vertex[20].normal = vec3(+0.00f, +1.00f, +0.00f);         // Normal


	vertex[21].position = vec3(+0.25f, +0.25f, +1.00f);         // 21
	vertex[21].color = vec3(+1.00f, +0.00f, +0.00f);		  // Color
	vertex[21].normal = vec3(+0.00f, +1.00f, +0.00f);         // Normal


	vertex[22].position = vec3(-0.25f, +0.25f, +1.00f);         // 22
	vertex[22].color = vec3(+1.00f, +0.00f, +0.00f);		  // Color
	vertex[22].normal = vec3(+0.00f, +1.00f, +0.00f);         // Normal


	vertex[23].position = vec3(-0.25f, +0.25f, -0.25f);         // 23
	vertex[23].color = vec3(+1.00f, +0.00f, +0.00f);		  // Color
	vertex[23].normal = vec3(+0.00f, +1.00f, +0.00f);         // Normal


	// Bottom side of back of arrow
	vertex[24].position = vec3(+0.25f, -0.25f, -0.25f);         // 24
	vertex[24].color = vec3(+0.00f, +0.00f, +1.00f);		  // Color
	vertex[24].normal = vec3(+0.00f, -1.00f, +0.00f);         // Normal


	vertex[25].position = vec3(+0.25f, -0.25f, +1.00f);         // 25
	vertex[25].color = vec3(+0.00f, +0.00f, +1.00f);		  // Color
	vertex[25].normal = vec3(+0.00f, -1.00f, +0.00f);         // Normal


	vertex[26].position = vec3(-0.25f, -0.25f, +1.00f);         // 26
	vertex[26].color = vec3(+0.00f, +0.00f, +1.00f);		  // Color
	vertex[26].normal = vec3(+0.00f, -1.00f, +0.00f);         // Normal


	vertex[27].position = vec3(-0.25f, -0.25f, -0.25f);         // 27
	vertex[27].color = vec3(+0.00f, +0.00f, +1.00f);		  // Color
	vertex[27].normal = vec3(+0.00f, -1.00f, +0.00f);         // Normal


	// Right side of back of arrow
	vertex[28].position = vec3(+0.25f, +0.25f, -0.25f);         // 28
	vertex[28].color = vec3(+0.60f, +1.00f, +0.00f);		  // Color
	vertex[28].normal = vec3(+1.00f, +0.00f, +0.00f);         // Normal

	vertex[29].position = vec3(+0.25f, -0.25f, -0.25f);         // 29
	vertex[29].color = vec3(+0.60f, +1.00f, +0.00f);		  // Color
	vertex[29].normal = vec3(+1.00f, +0.00f, +0.00f);         // Normal

	vertex[30].position = vec3(+0.25f, -0.25f, +1.00f);         // 30
	vertex[30].color = vec3(+0.60f, +1.00f, +0.00f);		  // Color
	vertex[30].normal = vec3(+1.00f, +0.00f, +0.00f);         // Normal

	vertex[31].position = vec3(+0.25f, +0.25f, +1.00f);         // 31
	vertex[31].color = vec3(+0.60f, +1.00f, +0.00f);		  // Color
	vertex[31].normal = vec3(+1.00f, +0.00f, +0.00f);         // Normal

	// Left side of back of arrow
	vertex[32].position = vec3(-0.25f, +0.25f, -0.25f);         // 32
	vertex[32].color = vec3(+0.00f, +1.00f, +0.00f);		  // Color
	vertex[32].normal = vec3(-1.00f, +0.00f, +0.00f);         // Normal

	vertex[33].position = vec3(-0.25f, -0.25f, -0.25f);         // 33
	vertex[33].color = vec3(+0.00f, +1.00f, +0.00f);		  // Color
	vertex[33].normal = vec3(-1.00f, +0.00f, +0.00f);         // Normal

	vertex[34].position = vec3(-0.25f, -0.25f, +1.00f);         // 34
	vertex[34].color = vec3(+0.00f, +1.00f, +0.00f);		  // Color
	vertex[34].normal = vec3(-1.00f, +0.00f, +0.00f);         // Normal

	vertex[35].position = vec3(-0.25f, +0.25f, +1.00f);         // 35
	vertex[35].color = vec3(+0.00f, +1.00f, +0.00f);		  // Color
	vertex[35].normal = vec3(-1.00f, +0.00f, +0.00f);         // Normal

	// Back side of back of arrow
	vertex[36].position = vec3(-0.25f, +0.25f, +1.00f);         // 36
	vertex[36].color = vec3(+0.50f, +0.50f, +0.50f);		  // Color
	vertex[36].normal = vec3(+0.00f, +0.00f, +1.00f);         // Normal

	vertex[37].position = vec3(+0.25f, +0.25f, +1.00f);         // 37
	vertex[37].color = vec3(+0.50f, +0.50f, +0.50f);		  // Color
	vertex[37].normal = vec3(+0.00f, +0.00f, +1.00f);         // Normal

	vertex[38].position = vec3(-0.25f, -0.25f, +1.00f);         // 38
	vertex[38].color = vec3(+0.50f, +0.50f, +0.50f);		  // Color
	vertex[38].normal = vec3(+0.00f, +0.00f, +1.00f);         // Normal

	vertex[39].position = vec3(+0.25f, -0.25f, +1.00f);         // 39
	vertex[39].color = vec3(+0.50f, +0.50f, +0.50f);		  // Color
	vertex[39].normal = vec3(+0.00f, +0.00f, +1.00f);         // Normal
	

	GLuint numIndices = 60;
	GLushort* indices = new GLushort[numIndices];

	indices[0] = 0; indices[1] = 1; indices[2] = 2; // Top
	indices[3] = 0; indices[4] = 2; indices[5] = 3;
	indices[6] = 4; indices[7] = 6; indices[8] = 5; // Bottom
	indices[9] = 4; indices[10] = 7; indices[11] = 6;
	indices[12] = 8; indices[13] = 10; indices[14] = 9; // Right side of arrow tip
	indices[15] = 8; indices[16] = 11; indices[17] = 10;
	indices[18] = 12; indices[19] = 15; indices[20] = 13; // Left side of arrow tip
	indices[21] = 12; indices[22] = 14; indices[23] = 15;
	indices[24] = 16; indices[25] = 19; indices[26] = 17; // Back side of arrow tip
	indices[27] = 16; indices[28] = 18; indices[29] = 19;
	indices[30] = 20; indices[31] = 22; indices[32] = 21; // Top side of back of arrow
	indices[33] = 20; indices[34] = 23; indices[35] = 22;
	indices[36] = 24; indices[37] = 25; indices[38] = 26; // Bottom side of back of arrow
	indices[39] = 24; indices[40] = 26; indices[41] = 27;
	indices[42] = 28; indices[43] = 30; indices[44] = 29; // Right side of back of arrow
	indices[45] = 28; indices[46] = 31; indices[47] = 30;
	indices[48] = 32; indices[49] = 33; indices[50] = 34; // Left side of back of arrow
	indices[51] = 32; indices[52] = 34; indices[53] = 35;
	indices[54] = 36; indices[55] = 39; indices[56] = 37; // Back side of back of arrow
	indices[57] = 36; indices[58] = 38; indices[59] = 39;

	
	MeshData* meshdata = new MeshData(vertex, numVertices, indices, numIndices);
	return meshdata;
}

Vertex* ShapeGenerator::makePlaneVerts(int dimensions, glm::vec3 color ,bool generateRandomColor)
{
	int numVertices = dimensions * dimensions;
	int half = dimensions / 2;
	Vertex* vertices = new Vertex[numVertices];
	for (int i = 0; i < dimensions; i++)
	{
		for (int j = 0; j < dimensions; j++)
		{
			Vertex& thisVert = vertices[i * dimensions + j];
			thisVert.position.x = j - half;
			thisVert.position.z = i - half;
			thisVert.position.y = 0;
			thisVert.normal = glm::vec3(0, 1, 0);
			if (generateRandomColor)
				thisVert.color = ColorUtils::randomColor();
			else
				thisVert.color = color;
		}
	}
	return vertices;
}

GLushort* ShapeGenerator::makePlaneIndices(int dimensions)
{
	int numIndices = (dimensions - 1) * (dimensions - 1) * 2 * 3; // 2 triangles per square, 3 indices per triangle
	GLushort* indices = new unsigned short[numIndices];
	int runner = 0;
	for (int row = 0; row < dimensions - 1; row++)
	{
		for (int col = 0; col < dimensions - 1; col++)
		{
			indices[runner++] = dimensions * row + col;
			indices[runner++] = dimensions * row + col + dimensions;
			indices[runner++] = dimensions * row + col + dimensions + 1;

			indices[runner++] = dimensions * row + col;
			indices[runner++] = dimensions * row + col + dimensions + 1;
			indices[runner++] = dimensions * row + col + 1;
		}
	}
	assert(runner = numIndices);
	return indices;
}

MeshData* ShapeGenerator::makePlane(uint dimensions, glm::vec3 color, bool generateRandomColor)
{

	int numVertices = dimensions * dimensions;
	Vertex* vertices = makePlaneVerts(dimensions, color, generateRandomColor);

	int numIndices = (dimensions - 1) * (dimensions - 1) * 2 * 3; // 2 triangles per square, 3 indices per triangle
	GLushort* indices = makePlaneIndices(dimensions);

	MeshData* meshData = new MeshData(vertices, numVertices, indices, numIndices);
	return meshData;
}





#include "Common\Geometry\Premitives\TeapotData.h"

MeshData* ShapeGenerator::makeTeapot(uint tesselation, const glm::mat4& lidTransform)
{

	GLuint numVertices = 32 * (tesselation + 1) * (tesselation + 1);
	uint faces = tesselation * tesselation * 32;
	float* vertices = new float[numVertices * 3];
	float* normals = new float[numVertices * 3];
	float* textureCoordinates = new float[numVertices * 2];
	GLuint numIndices = faces * 6;
	GLushort* indices = new unsigned short[numIndices];

	generatePatches(vertices, normals, textureCoordinates, indices, tesselation);
	moveLid(tesselation, vertices, lidTransform);

	// Adapt/convert their data format to mine
	Vertex* gVerxtex = new Vertex[numVertices];
	for (uint i = 0; i < numVertices; i++)
	{
		Vertex& v = gVerxtex[i];
		v.position.x = vertices[i * 3 + 0];
		v.position.y = vertices[i * 3 + 1];
		v.position.z = vertices[i * 3 + 2];
		v.normal.x = normals[i * 3 + 0];
		v.normal.y = normals[i * 3 + 1];
		v.normal.z = normals[i * 3 + 2];
		v.color = ColorUtils::randomColor();
	}
	MeshData* meshData = new MeshData(gVerxtex, numVertices, indices, numIndices);
	return meshData;
}

void ShapeGenerator::generatePatches(float * v, float * n, float * tc, unsigned short* el, int grid) {
	float * B = new float[4 * (grid + 1)];  // Pre-computed Bernstein basis functions
	float * dB = new float[4 * (grid + 1)]; // Pre-computed derivitives of basis functions

	int idx = 0, elIndex = 0, tcIndex = 0;

	// Pre-compute the basis functions  (Bernstein polynomials)
	// and their derivatives
	computeBasisFunctions(B, dB, grid);

	// Build each patch
	// The rim
	buildPatchReflect(0, B, dB, v, n, tc, el, idx, elIndex, tcIndex, grid, true, true);
	// The body
	buildPatchReflect(1, B, dB, v, n, tc, el, idx, elIndex, tcIndex, grid, true, true);
	buildPatchReflect(2, B, dB, v, n, tc, el, idx, elIndex, tcIndex, grid, true, true);
	// The lid
	buildPatchReflect(3, B, dB, v, n, tc, el, idx, elIndex, tcIndex, grid, true, true);
	buildPatchReflect(4, B, dB, v, n, tc, el, idx, elIndex, tcIndex, grid, true, true);
	// The bottom
	buildPatchReflect(5, B, dB, v, n, tc, el, idx, elIndex, tcIndex, grid, true, true);
	// The handle
	buildPatchReflect(6, B, dB, v, n, tc, el, idx, elIndex, tcIndex, grid, false, true);
	buildPatchReflect(7, B, dB, v, n, tc, el, idx, elIndex, tcIndex, grid, false, true);
	// The spout
	buildPatchReflect(8, B, dB, v, n, tc, el, idx, elIndex, tcIndex, grid, false, true);
	buildPatchReflect(9, B, dB, v, n, tc, el, idx, elIndex, tcIndex, grid, false, true);

	delete[] B;
	delete[] dB;
}

void ShapeGenerator::moveLid(int grid, float *v, mat4 lidTransform) {

	int start = 3 * 12 * (grid + 1) * (grid + 1);
	int end = 3 * 20 * (grid + 1) * (grid + 1);

	for (int i = start; i < end; i += 3)
	{
		glm::vec4 vert = glm::vec4(v[i], v[i + 1], v[i + 2], 1.0f);
		vert = lidTransform * vert;
		v[i] = vert.x;
		v[i + 1] = vert.y;
		v[i + 2] = vert.z;
	}
}

void ShapeGenerator::buildPatchReflect(int patchNum,
	float *B, float *dB,
	float *v, float *n,
	float *tc, unsigned short *el,
	int &index, int &elIndex, int &tcIndex, int grid,
	bool reflectX, bool reflectY)
{
	glm::vec3 patch[4][4];
	glm::vec3 patchRevV[4][4];
	getPatch(patchNum, patch, false);
	getPatch(patchNum, patchRevV, true);

	// Patch without modification
	buildPatch(patch, B, dB, v, n, tc, el,
		index, elIndex, tcIndex, grid, mat3(1.0f), true);

	// Patch reflected in x
	if (reflectX) {
		buildPatch(patchRevV, B, dB, v, n, tc, el,
			index, elIndex, tcIndex, grid, glm::mat3(glm::vec3(-1.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f),
			glm::vec3(0.0f, 0.0f, 1.0f)), false);
	}

	// Patch reflected in y
	if (reflectY) {
		buildPatch(patchRevV, B, dB, v, n, tc, el,
			index, elIndex, tcIndex, grid, glm::mat3(glm::vec3(1.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, -1.0f, 0.0f),
			glm::vec3(0.0f, 0.0f, 1.0f)), false);
	}

	// Patch reflected in x and y
	if (reflectX && reflectY) {
		buildPatch(patch, B, dB, v, n, tc, el,
			index, elIndex, tcIndex, grid, glm::mat3(glm::vec3(-1.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, -1.0f, 0.0f),
			glm::vec3(0.0f, 0.0f, 1.0f)), true);
	}
}

void ShapeGenerator::buildPatch(glm::vec3 patch[][4],
	float *B, float *dB,
	float *v, float *n, float *tc,
	unsigned short *el,
	int &index, int &elIndex, int &tcIndex, int grid, glm::mat3 reflect,
	bool invertNormal)
{
	int startIndex = index / 3;
	float tcFactor = 1.0f / grid;

	for (int i = 0; i <= grid; i++)
	{
		for (int j = 0; j <= grid; j++)
		{
			glm::vec3 pt = reflect * evaluate(i, j, B, patch);
			glm::vec3 norm = reflect * evaluateNormal(i, j, B, dB, patch);
			if (invertNormal)
				norm = -norm;

			v[index] = pt.x;
			v[index + 1] = pt.y;
			v[index + 2] = pt.z;

			n[index] = norm.x;
			n[index + 1] = norm.y;
			n[index + 2] = norm.z;

			tc[tcIndex] = i * tcFactor;
			tc[tcIndex + 1] = j * tcFactor;

			index += 3;
			tcIndex += 2;
		}
	}

	for (int i = 0; i < grid; i++)
	{
		int iStart = i * (grid + 1) + startIndex;
		int nextiStart = (i + 1) * (grid + 1) + startIndex;
		for (int j = 0; j < grid; j++)
		{
			el[elIndex] = iStart + j;
			el[elIndex + 1] = nextiStart + j + 1;
			el[elIndex + 2] = nextiStart + j;

			el[elIndex + 3] = iStart + j;
			el[elIndex + 4] = iStart + j + 1;
			el[elIndex + 5] = nextiStart + j + 1;

			elIndex += 6;
		}
	}
}

#include "Common\Geometry\Premitives\TeapotData.h"

void ShapeGenerator::getPatch(int patchNum, glm::vec3 patch[][4], bool reverseV)
{
	for (int u = 0; u < 4; u++) {          // Loop in u direction
		for (int v = 0; v < 4; v++) {     // Loop in v direction
			if (reverseV) {
				patch[u][v] = glm::vec3(
					Teapot::cpdata[Teapot::patchdata[patchNum][u * 4 + (3 - v)]][0],
					Teapot::cpdata[Teapot::patchdata[patchNum][u * 4 + (3 - v)]][1],
					Teapot::cpdata[Teapot::patchdata[patchNum][u * 4 + (3 - v)]][2]
					);
			}
			else {
				patch[u][v] = glm::vec3(
					Teapot::cpdata[Teapot::patchdata[patchNum][u * 4 + v]][0],
					Teapot::cpdata[Teapot::patchdata[patchNum][u * 4 + v]][1],
					Teapot::cpdata[Teapot::patchdata[patchNum][u * 4 + v]][2]
					);
			}
		}
	}
}

void ShapeGenerator::computeBasisFunctions(float * B, float * dB, int grid) {
	float inc = 1.0f / grid;
	for (int i = 0; i <= grid; i++)
	{
		float t = i * inc;
		float tSqr = t * t;
		float oneMinusT = (1.0f - t);
		float oneMinusT2 = oneMinusT * oneMinusT;

		B[i * 4 + 0] = oneMinusT * oneMinusT2;
		B[i * 4 + 1] = 3.0f * oneMinusT2 * t;
		B[i * 4 + 2] = 3.0f * oneMinusT * tSqr;
		B[i * 4 + 3] = t * tSqr;

		dB[i * 4 + 0] = -3.0f * oneMinusT2;
		dB[i * 4 + 1] = -6.0f * t * oneMinusT + 3.0f * oneMinusT2;
		dB[i * 4 + 2] = -3.0f * tSqr + 6.0f * t * oneMinusT;
		dB[i * 4 + 3] = 3.0f * tSqr;
	}
}




glm::vec3 ShapeGenerator::evaluate(int gridU, int gridV, float *B, glm::vec3 patch[][4])
{
	glm::vec3 p(0.0f, 0.0f, 0.0f);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			p += patch[i][j] * B[gridU * 4 + i] * B[gridV * 4 + j];
		}
	}
	return p;
}

glm::vec3 ShapeGenerator::evaluateNormal(int gridU, int gridV, float *B, float *dB, glm::vec3 patch[][4])
{
	glm::vec3 du(0.0f, 0.0f, 0.0f);
	glm::vec3 dv(0.0f, 0.0f, 0.0f);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			du += patch[i][j] * dB[gridU * 4 + i] * B[gridV * 4 + j];
			dv += patch[i][j] * B[gridU * 4 + i] * dB[gridV * 4 + j];
		}
	}
	return glm::normalize(glm::cross(du, dv));
}

MeshData ShapeGenerator::generateNormals(const MeshData& data)
{

	/*MeshData ret;

	ret.numVertices = data.numVertices * 2;
	ret.vertices = new Vertex[ret.numVertices];
	glm::vec3 white(1.0f, 1.0f, 1.0f);

	for (int i = 0; i < data.numVertices; i++)
	{
	uint vertIndex = i * 2;
	Vertex& v1 = ret.vertices[vertIndex];
	Vertex& v2 = ret.vertices[vertIndex + 1];
	const Vertex& sourceVertex = data.vertices[i];
	v1.position = sourceVertex.position;
	v2.position = sourceVertex.position + sourceVertex.normal;
	v1.color = v2.color = white;
	}

	ret.numIndices = ret.numVertices;
	ret.indices = new GLushort[ret.numIndices];
	for (int i = 0; i < ret.numIndices; i++)
	ret.indices[i] = i;
	return ret;*/


	MeshData s(NULL, 0, NULL, 0);
	return s;
}



GLushort* ShapeGenerator::makePlaneUnseamedIndices(int tesselation)
{

	uint dimensions = tesselation * tesselation;
	uint numIndices = dimensions * 2 * 3; // 2 triangles per square, 3 indices per triangle
	GLushort* indices = new unsigned short[numIndices];
	int runner = 0;
	for (int row = 0; row < tesselation; row++)
	{
		// This code is crap but works, and I'm not in the mood right now to clean it up
		for (int col = 0; col < tesselation; col++)
		{
			// Bottom left triangle
			indices[runner++] = tesselation * row + col;
			// One row down unless it's the bottom row, 
			indices[runner++] = (row + 1 == tesselation ? 0 : tesselation * row + tesselation) + col;
			// Move to vert right of this one unless it's the last vert,
			// which we connect to the first vert in the row
			// the % dimensions at the end accounts for the last row hooking to the first row
			indices[runner++] = (tesselation * row + col + tesselation + (col + 1 == tesselation ? -tesselation + 1 : 1)) % dimensions;

			// Upper right triangle
			indices[runner++] = tesselation * row + col;
			if (col + 1 == tesselation && row + 1 == tesselation)
			{
				// Very last vert
				indices[runner++] = 0;
			}
			else if (col + 1 == tesselation)
			{
				// Last vert on this row
				// Check if we need to connect it to zeroeth row or the next row
				if (row + 1 == tesselation)
				{
					// Tie to zeroeth row
					indices[runner++] = col + 1;
				}
				else
				{
					// Tie to next row
					indices[runner++] = tesselation * row + col + 1;
				}
			}
			else
			{
				// Regular interior vert
				// the % dimensions at the end accounts for the last row hooking to the first row
				indices[runner++] = (tesselation * row + col + tesselation + 1) % dimensions;
			}
			indices[runner++] = tesselation * row + col + (col + 1 == tesselation ? -col : 1);
		}
	}
	return indices;
}


MeshData* ShapeGenerator::makeSphere(uint tesselation)
{
	/*MeshData ret = makePlaneVerts(tesselation);
	MeshData ret2 = makePlaneIndices(tesselation);
	ret.indices = ret2.indices;
	ret.numIndices = ret2.numIndices;

	uint dimensions = tesselation;
	const float RADIUS = 1.0f;
	const double CIRCLE = PI * 2;
	const double SLICE_ANGLE = CIRCLE / (dimensions - 1);
	for (size_t col = 0; col < dimensions; col++)
	{
	double phi = -SLICE_ANGLE * col;
	for (size_t row = 0; row < dimensions; row++)
	{
	double theta = -(SLICE_ANGLE / 2.0) * row;
	size_t vertIndex = col * dimensions + row;
	Vertex& v = ret.vertices[vertIndex];
	v.position.x = RADIUS * cos(phi) * sin(theta);
	v.position.y = RADIUS * sin(phi) * sin(theta);
	v.position.z = RADIUS * cos(theta);
	v.normal = glm::normalize(v.position);
	}
	}
	return ret;*/
	return NULL;
}

MeshData* ShapeGenerator::makeTorus(uint tesselation)
{

	uint dimensions = tesselation * tesselation;
	uint numVertices = dimensions;
	Vertex* vertices = new Vertex[numVertices];

	float sliceAngle = 360 / tesselation;
	const float torusRadius = 1.0f;
	const float pipeRadius = 0.5f;
	for (uint round1 = 0; round1 < tesselation; round1++)
	{
		// Generate a circle on the xy plane, then
		// translate then rotate it into position
		glm::mat4 transform =
			glm::rotate(glm::mat4(), round1 * sliceAngle, glm::vec3(0.0f, 1.0f, 0.0f)) *
			glm::translate(glm::mat4(), glm::vec3(torusRadius, 0.0f, 0.0f));
		glm::mat3 normalTransform = (glm::mat3)transform;
		for (uint round2 = 0; round2 < tesselation; round2++)
		{
			Vertex& v = vertices[round1 * tesselation + round2];
			glm::vec4 glmVert(
				pipeRadius * cos(glm::radians(sliceAngle * round2)),
				pipeRadius * sin(glm::radians(sliceAngle * round2)),
				0,
				1.0f);
			glm::vec4 glmVertPrime = transform * glmVert;
			v.position = (glm::vec3)glmVertPrime;
			v.normal = glm::normalize(normalTransform * (glm::vec3)glmVert);
			v.color = ColorUtils::randomColor();
		}
	}

	GLushort* indices = makePlaneUnseamedIndices(tesselation);
	uint numIndices = dimensions * 2 * 3; // 2 triangles per square, 3 indices per triangle
	MeshData* ret = new MeshData(vertices, numVertices, indices, numIndices);
	return ret;

}


MeshData* ShapeGenerator::makePyramid()
{

	GLuint numVertices = 4;
	Vertex* vertices = new Vertex[numVertices];

	vertices[0].position = vec3(-1.0f, -1.0f, 0.5773f);
	vertices[0].color = vec3(+1.00f, +0.00f, +1.00f);
	vertices[0].normal = vec3(-0.0f, 0.0f, -0.0f);


	vertices[1].position = vec3(0.0f, -1.0f, -1.15475f);
	vertices[1].color = vec3(+0.00f, +1.00f, +1.00f);
	vertices[1].normal = vec3(-0.0f, 0.0f, -0.0f);

	vertices[2].position = vec3(1.0f, -1.0f, 0.5773f);
	vertices[2].color = vec3(+1.00f, +0.00f, +0.00f);
	vertices[2].normal = vec3(-0.0f, 0.0f, -0.0f);


	vertices[3].position = vec3(0.0f, 1.0f, 0.0f);
	vertices[3].color = vec3(+0.00f, +1.00f, +1.00f);
	vertices[3].normal = vec3(-0.0f, 0.0f, -0.0f);




	GLushort numIndices = 12;
	GLushort* indices = new GLushort[numIndices];
	indices[0] = 0;
	indices[1] = 3;
	indices[2] = 1;

	indices[3] = 1;
	indices[4] = 3;
	indices[5] = 2;

	indices[6] = 2;
	indices[7] = 3;
	indices[8] = 0;

	indices[9] = 1;
	indices[10] = 2;
	indices[11] = 0;



	for (unsigned int i = 0; i < numIndices; i += 3)
	{
		unsigned int index0 = indices[i];
		unsigned int index1 = indices[i + 1];
		unsigned int index2 = indices[i + 2];

		glm::vec3 v1 = vertices[index1].position - vertices[index0].position;
		glm::vec3 v2 = vertices[index2].position - vertices[index0].position;

		glm::vec3 normal = glm::cross(v1, v2);

		vertices[index0].normal += normal;
		vertices[index1].normal += normal;
		vertices[index2].normal += normal;

	}

	for (unsigned int v = 0; v < numVertices; v++)
	{
		glm::normalize(vertices[0].normal);
	}

	MeshData* meshData = new MeshData(vertices, numVertices, indices, numIndices);
	return meshData;
}


MeshData* ShapeGenerator::createAxis(float length)
{
	GLuint numVertices = 6;
	Vertex* vertices = new Vertex[numVertices];


	//Red
	vertices[0].position = vec3(0 ,0, 0);
	vertices[0].color = vec3(1, 0, 0);
	vertices[0].normal = vec3(0, 0, 0);

	vertices[1].position = vec3(length,0,0);
	vertices[1].color = vec3(1 , 0 , 0);
	vertices[1].normal = vec3(0, 0, 0);


	//Green

	vertices[2].position = vec3(0, 0, 0);
	vertices[2].color = vec3(0, 1, 0);
	vertices[2].normal = vec3(0, 0, 0);


	vertices[3].position = vec3(0 , 0 + length,  0);
	vertices[3].color = vec3(0, 1, 0);
	vertices[3].normal = vec3(0, 0, 0);


	//Blue
	vertices[4].position = vec3(0, 0, 0);
	vertices[4].color = vec3(0, 0, 1);
	vertices[4].normal = vec3(0, 0, 0);

	vertices[5].position = vec3(0, 0, 0 + length);
	vertices[5].color = vec3(0, 0, 1);
	vertices[5].normal = vec3(0, 0, 0);

	GLushort numIndices = 6;


	GLushort* indices = new GLushort[numIndices];
	indices[0] = 0;
	indices[1] = 1;

	indices[2] = 2;
	indices[3] = 3;

	indices[4] = 4;
	indices[5] = 5;


	MeshData* meshData = new MeshData(vertices, numVertices, indices, numIndices);
	return meshData;
}




MeshData* ShapeGenerator::createDirectionalWidget(float radius, int numSegments, int numDirectionalElements , vec3 color)
{
	GLuint numVertices = numSegments + numDirectionalElements;
	GLuint numIndices = 2*numSegments + 2*numDirectionalElements;

	Vertex* vertices = new Vertex[numVertices];
	GLushort* indices = new GLushort[numIndices];

	assert(numSegments % numDirectionalElements == 0);

	int alreadyFilledVertices = 0;
	int alreadyFilledIndices = 0;

	for (int count = 0; count < numSegments; count++)
	{
		float theta = 2.0f * PI * float(count) / float(numSegments);
		
		vertices[count].position = vec3(radius * cosf(theta), radius * sinf(theta), 0);
		vertices[count].color = color;

		alreadyFilledVertices++;

		if (count == numSegments-1)
		{
			indices[2 * count] = count;
			indices[2 * count + 1] = 0;
		}
		else
		{
			indices[2 * count] = count;
			indices[2 * count + 1] = count + 1;
		}

		alreadyFilledIndices += 2;
	}

	int step = numSegments / numDirectionalElements;

	assert(step != 0);

	for (int count = 0; count < numDirectionalElements; count++)
	{
		int index = step*count;
		float theta = 2.0f * PI * float(index) / float(numSegments);

		vertices[alreadyFilledVertices].position = vec3(radius * cosf(theta), radius * sinf(theta), 1);
		vertices[alreadyFilledVertices].color = color;

		indices[alreadyFilledIndices] = index;
		indices[alreadyFilledIndices + 1] = alreadyFilledVertices;

		alreadyFilledVertices++;
		alreadyFilledIndices += 2;
	}
	
	assert(alreadyFilledIndices == numIndices);
	assert(alreadyFilledVertices == numVertices);

	MeshData* meshData = new MeshData(vertices, numVertices, indices, numIndices);
	return meshData;

}


vector<MeshData*> ShapeGenerator::createShapeFromFile(string  fileName)
{
	vector<MeshData*> ret;
	Assimp::Importer importer = Assimp::Importer();
	const aiScene* scene =  importer.ReadFile(fileName, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs);
	if (scene)
	{
		return initFromScene(scene);
	}
	else
	{
		cout << "Error Creating Mesh from " << fileName;
	}

	return ret;
}


vector<MeshData*> ShapeGenerator::initFromScene(const aiScene* scene)
{
	vector<MeshData*> meshDataVector;
	
	for (int countM = 0; countM < scene->mNumMeshes; countM++)
	{
		const aiMesh* aiMeshIns = scene->mMeshes[countM];

		MeshData* meshData = new MeshData();
		meshDataVector.push_back(meshData);

		meshData->numVertices = aiMeshIns->mNumVertices;
		meshData->vertices = new Vertex[meshData->numVertices];

		meshData->numIndices = aiMeshIns->mNumFaces*3;
		meshData->indices = new GLushort[meshData->numIndices];

		GLuint indicesCountIndex = 0;
		for (int countV = 0; countV < aiMeshIns->mNumVertices ; countV++)
		{
			aiVector3D aiVectorIns = aiMeshIns->mVertices[countV];
			//const aiColor4D* aiColor4D = aiMeshIns->mColors[countV];
			const aiVector3D aiNormals = aiMeshIns->mNormals[countV];

			meshData->vertices[countV].position = glm::vec3(aiVectorIns.x, aiVectorIns.y, aiVectorIns.z);
			//meshData->vertices[countV].color = glm::vec3(aiColor4D->r, aiColor4D->g, aiColor4D->b);
			meshData->vertices[countV].normal = glm::vec3(aiNormals.x, aiNormals.y, aiNormals.z);
			
		}

		for (int countI = 0; countI < aiMeshIns->mNumFaces; countI++)
		{
			aiFace aiFaceIns =  aiMeshIns->mFaces[countI];
			assert(aiFaceIns.mNumIndices == 3);

			meshData->indices[indicesCountIndex] = aiFaceIns.mIndices[0];
			meshData->indices[indicesCountIndex+1] = aiFaceIns.mIndices[1];
			meshData->indices[indicesCountIndex+2] = aiFaceIns.mIndices[2];

			indicesCountIndex+=3;
		}




	}

	return meshDataVector;
}