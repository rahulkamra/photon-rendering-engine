#pragma once
#include <vector>
#include <GL/glew.h>
#include <assert.h>
#include <ogldev_util.h>
#include <ogldev_types.h>
#include "Common\GameObj\GameObj.h"
#include "Camera.h"
#include "Common\Materials\MaterialsManager.h"
#include <Electron.h>
#include "Common\Lights\DiffuseLightManager.h"

class BasicMeshRenderer
{

protected :
	std::vector<GameObj> renderedItems;
	std::vector<GLuint> vertexArrayAttribs;

	GLuint IBO;
	GLuint VBO;


	void createBuffers()
	{
		deleteBuffers();
		createVertexBuffer();
		createIndexBuffer();
	}

	void deleteBuffers()
	{
		glDeleteBuffers(1, &IBO);
		glDeleteBuffers(1, &VBO);
	}
	void createVertexBuffer()
	{
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, getVertexBufferSize(), 0, GL_DYNAMIC_DRAW);
	}

	void createIndexBuffer()
	{
		glGenBuffers(1, &IBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, getIndexBufferSize() , 0, GL_DYNAMIC_DRAW);
	}


	GLsizei getIndexBufferSize()
	{
		/*
		GLsizei totalSize= 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			totalSize += gameObj.shape->indexBufferSize();
		}

		return totalSize;*/
	}

	GLsizei getNumIndices()
	{
		/*
		GLsizei totalSize = 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			totalSize += gameObj.shape->numIndices;
		}
		return totalSize;*/
	}

	GLsizei getVertexBufferSize()
	{
		/*
		GLsizei totalSize = 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			totalSize += gameObj.shape->vertexBufferSize();
		}

		return totalSize;*/
	}


	void redefineVertexSubData()
	{
		/*
		GLintptr offset = 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			
			glBufferSubData(GL_ARRAY_BUFFER, offset, gameObj.shape->vertexBufferSize(), gameObj.shape->vertices);
			offset += gameObj.shape->vertexBufferSize();
		}*/
	}

	void redefineIndexSubData()
	{
		/*
		GLintptr offset = 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, gameObj.shape->indexBufferSize(), gameObj.shape->indices);
			offset += gameObj.shape->indexBufferSize();
		}*/
	}

	GLuint vertexArrayId;
	void setupData(GameObj gameObj)
	{
		/*
		GLuint vertexArrayId = 0;
		glGenVertexArrays(1, &vertexArrayId);
		vertexArrayAttribs.push_back(vertexArrayId);

		glBindVertexArray(vertexArrayId);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		GLsizei sizeOfVertex = 9 * sizeof(float);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeOfVertex, (void *)(getVertexBufferSize() - gameObj.shape->vertexBufferSize()));
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeOfVertex, (void *)(getVertexBufferSize() - gameObj.shape->vertexBufferSize() + sizeof(float)* 3));
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeOfVertex, (void *)(getVertexBufferSize() - gameObj.shape->vertexBufferSize() + sizeof(float)* 6));

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBindVertexArray(0);*/
	}

	/*void addDirectionalLights()
	{
		if (Electron::lights.size() > 0)
		{
			vec3 light = Electron::lights.at(0);
			GLuint directionalLightUniformLocation = glGetUniformLocation(basicrenderer.shaderProgramId, "directionalLight");
			glUniform3fv(directionalLightUniformLocation, 1, &light[0]);
		}
	}*/

public :

	void addItem(GameObj gameObj)
	{
		renderedItems.push_back(gameObj);
		createBuffers();
		redefineVertexSubData();
		redefineIndexSubData();
		setupData(gameObj);
	}



	virtual void draw()
	{
		GLuint offset = 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			GLuint vertexArrayAtrrib = vertexArrayAttribs.at(count);
			glBindVertexArray(vertexArrayAtrrib);
			
			mat4 modelToWorld = gameObj.transform.modelTransformtionMatrix();
			mat4 worldToView = Camera::getCamera()->worldToProjection(modelToWorld);

			/*GLuint shaderProgramId = MaterialsManager::getMaterial(gameObj.material);
			glUseProgram(shaderProgramId);

			GLint worldToViewLocation = glGetUniformLocation(shaderProgramId, "worldToView");
			glUniformMatrix4fv(worldToViewLocation, 1, GL_FALSE, &worldToView[0][0]);

			GLint modelToWorldLocation = glGetUniformLocation(shaderProgramId, "modelToWorld");
			glUniformMatrix4fv(modelToWorldLocation, 1, GL_FALSE, &modelToWorld[0][0]);

			GLuint cameraWorldUniformLocation = glGetUniformLocation(shaderProgramId, "cameraWorld");
			glUniform3fv(cameraWorldUniformLocation, 1, &Camera::getCamera()->position[0]);

			GLuint anbientLightUniformLocation = glGetUniformLocation(shaderProgramId, "ambientLight");
			glUniform3fv(anbientLightUniformLocation, 1, &Electron::ambientLight[0]);

			DiffuseLightManager::addAttribs(shaderProgramId);
			glDrawElements(GL_TRIANGLES, gameObj.shape->numIndices, GL_UNSIGNED_SHORT, (void *)offset);
			offset += gameObj.shape->indexBufferSize();*/

		}
	}
};