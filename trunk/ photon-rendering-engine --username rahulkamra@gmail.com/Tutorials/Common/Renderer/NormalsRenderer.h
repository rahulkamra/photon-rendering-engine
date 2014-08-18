#pragma once
#include <vector>
#include <GL/glew.h>
#include <assert.h>
#include <ogldev_util.h>
#include <ogldev_types.h>
#include "Common\GameObj\GameObj.h"
#include "Camera.h"


class NormalsRenderer
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
		GLsizei totalSize= 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			//totalSize += gameObj.normalsShape.indexBufferSize();
		}

		return totalSize;
	}

	GLsizei getNumIndices()
	{
		GLsizei totalSize = 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			//totalSize += gameObj.normalsShape.numIndices;
		}
		return totalSize;
	}

	GLsizei getVertexBufferSize()
	{
		GLsizei totalSize = 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			//totalSize += gameObj.normalsShape.vertexBufferSize();
		}

		return totalSize;
	}


	void redefineVertexSubData()
	{
		GLintptr offset = 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			
			//glBufferSubData(GL_ARRAY_BUFFER, offset, gameObj.normalsShape.vertexBufferSize(), gameObj.normalsShape.vertices);
			//offset += gameObj.normalsShape.vertexBufferSize();
		}
	}

	void redefineIndexSubData()
	{
		GLintptr offset = 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			//glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, offset, gameObj.normalsShape.indexBufferSize(), gameObj.normalsShape.indices);
			//offset += gameObj.normalsShape.indexBufferSize();
		}
	}

	GLuint vertexArrayId;
	void setupData(GameObj gameObj)
	{

		GLuint vertexArrayId = 0;
		glGenVertexArrays(1, &vertexArrayId);
		vertexArrayAttribs.push_back(vertexArrayId);

		glBindVertexArray(vertexArrayId);
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(getVertexBufferSize() - gameObj.normalsShape.vertexBufferSize()));
		//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void *)(getVertexBufferSize() - gameObj.normalsShape.vertexBufferSize() + sizeof(float)* 3));

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
		glBindVertexArray(0);
	}


public :

	GLuint shaderProgramId;
	void addItem(GameObj gameObj)
	{
		renderedItems.push_back(gameObj);
		createBuffers();
		redefineVertexSubData();
		redefineIndexSubData();
		setupData(gameObj);
	}



	void draw()
	{
		GLuint offset = 0;
		for (int count = 0; count < renderedItems.size(); count++)
		{
			GameObj gameObj = renderedItems.at(count);
			GLuint vertexArrayAtrrib = vertexArrayAttribs.at(count);
			glBindVertexArray(vertexArrayAtrrib);
			
			mat4 worldToView = Camera::getCamera()->worldToProjection(gameObj.transform.modelTransformtionMatrix());

			GLint transformMatrixLocation = glGetUniformLocation(shaderProgramId, "worldToView");
			glUniformMatrix4fv(transformMatrixLocation, 1, GL_FALSE, &worldToView[0][0]);

			//glDrawElements(GL_LINES, gameObj.normalsShape.numIndices, GL_UNSIGNED_SHORT, (void *)offset);
			//offset += gameObj.normalsShape.indexBufferSize();

		}
	}
};