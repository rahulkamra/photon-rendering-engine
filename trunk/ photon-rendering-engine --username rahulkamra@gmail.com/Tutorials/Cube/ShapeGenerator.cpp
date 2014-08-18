#pragma once
#include <Cube\ShapeGenerator.h>

ShapeData ShapeGenerator::makeTriangles()
{
	ShapeData shapeData;
	int numVertices = 3;	
	
	Vertex* vertices = new Vertex[numVertices];
	
	vertices[0] = { Vector3f(0.0f, 1.0f, 0.0f),
		Vector3f(1.0f, 0.0f, 0.0f) };

	vertices[1] = { Vector3f(-1.0f, -1.0f, 0.0f),
		Vector3f(0.0f, 1.0f, 0.0f) };

	vertices[2] = { Vector3f(1.0f, -1.0f, 0.0f),
		Vector3f(0.0f, 0.0f, 1.0f) };

	//memcpy(shapeData.vertices, Vertices, sizeof(Vertices));


	shapeData.setVertices(vertices, numVertices);

	GLushort* indices = new GLushort[numVertices];

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;

	shapeData.setIndices(indices, numVertices);
	
	return shapeData;

}



ShapeData ShapeGenerator::makeCube()
{
	ShapeData shapeData;
	int numVertices = 24;

	Vertex* vertices = new Vertex[numVertices];

	vertices[0] = { Vector3f(-1.0f, 1.0f, 1.0f),
		Vector3f(1.0f, 0.0f, 0.0f) };
	vertices[1] = { Vector3f(1.0f, 1.0f, 1.0f),
		Vector3f(0.0f, 1.0f, 0.0f) };
	vertices[2] = { Vector3f(1.0f, 1.0f, -1.0f),
		Vector3f(0.0f, 0.0f, 1.0f) };
	vertices[3] = { Vector3f(-1.0f, 1.0f, -1.0f),
		Vector3f(1.0f, 1.0f, 1.0f) };

	vertices[4] = { Vector3f(-1.0f, 1.0f, -1.0f),
		Vector3f(1.0f, 0.0f, 1.0f) };
	vertices[5] = { Vector3f(1.0f, 1.0f, -1.0f),
		Vector3f(0.0f, 0.5f, 0.2f) };
	vertices[6] = { Vector3f(1.0f, -1.0f, -1.0f),
		Vector3f(0.8f, 0.6f, 0.4f) };
	vertices[7] = { Vector3f(-1.0f, -1.0f, -1.0f),
		Vector3f(0.3f, 1.0f, 0.5f) };

	vertices[8] = { Vector3f(1.0f, 1.0f, -1.0f),
		Vector3f(0.2f, 0.5f, 0.2f) };
	vertices[9] = { Vector3f(1.0f, 1.0f, 1.0f),
		Vector3f(0.9f, 0.3f, 0.7f) };
	vertices[10] = { Vector3f(1.0f, -1.0f, 1.0f),
		Vector3f(0.3f, 0.7f, 0.5f) };
	vertices[11] = { Vector3f(1.0f, -1.0f, -1.0f),
		Vector3f(0.5f, 0.7f, 0.5f) };

	vertices[12] = { Vector3f(-1.0f, 1.0f,1.0f),
		Vector3f(0.7f, 0.8f, 0.2f) };
	vertices[13] = { Vector3f(-1.0f, 1.0f, -1.0f),
		Vector3f(0.5f, 0.7f, 0.3f) };
	vertices[14] = { Vector3f(-1.0f, -1.0f, -1.0f),
		Vector3f(0.4f, 0.7f, 0.7f) };
	vertices[15] = { Vector3f(-1.0f, -1.0f, 1.0f),
		Vector3f(0.2f, 0.5f, 1.0f) };

	vertices[16] = { Vector3f(1.0f, 1.0f, 1.0f),
		Vector3f(0.6f, 1.0f, 0.7f) };
	vertices[17] = { Vector3f(-1.0f, 1.0f, 1.0f),
		Vector3f(0.6f, 0.4f, 0.8f) };
	vertices[18] = { Vector3f(-1.0f, -1.0f, 1.0f),
		Vector3f(0.2f, 0.8f, 0.7f) };
	vertices[19] = { Vector3f(1.0f, -1.0f, 1.0f),
		Vector3f(0.2f, 0.7f, 1.0f) };


	vertices[20] = { Vector3f(1.0f, -1.0f, -1.0f),
		Vector3f(0.8f, 0.3f, 0.7f) };
	vertices[21] = { Vector3f(-1.0f, -1.0f, -1.0f),
		Vector3f(0.8f, 0.9f, 0.5f) };
	vertices[22] = { Vector3f(-1.0f, -1.0f, 1.0f),
		Vector3f(0.5f, 0.8f, 0.5f) };
	vertices[23] = { Vector3f(1.0f, -1.0f, 1.0f),
		Vector3f(0.9f, 1.0f, 0.2f) };

	shapeData.setVertices(vertices, numVertices);

	int numIndices = 36;
	GLushort* indices = new GLushort[numIndices];

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 0;
	indices[4] = 2;
	indices[5] = 3;

	indices[6] = 4;
	indices[7] = 5;
	indices[8] = 6;
	indices[9] = 4;
	indices[10] = 6;
	indices[11] = 7;

	indices[12] = 8;
	indices[13] = 9;
	indices[14] = 10;
	indices[15] = 8;
	indices[16] = 10;
	indices[17] = 11;

	indices[18] = 12;
	indices[19] = 13;
	indices[20] = 14;
	indices[21] = 12;
	indices[22] = 14;
	indices[23] = 15;


	indices[24] = 16;
	indices[25] = 17;
	indices[26] = 18;
	indices[27] = 16;
	indices[28] = 18;
	indices[29] = 19;


	indices[30] = 20;
	indices[31] = 22;
	indices[32] = 21;
	indices[33] = 20;
	indices[34] = 23;
	indices[35] = 22;

	shapeData.setIndices(indices, numIndices);
	return shapeData;
}
