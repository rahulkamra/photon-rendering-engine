#include "Mesh.h"
#include "Camera.h"
#include "Electron.h"
#include "Common\Materials\Material.h"
#include "Common\Materials\MaterialsManager.h"
#include "Common\Lights\DiffuseLightManager.h"

Mesh::Mesh(MeshData* meshData)
{
	this->meshData = meshData;
}

Mesh::~Mesh()
{
	//glDeleteBuffers(1, &IBO);
	//glDeleteBuffers(1, &VBO);
}



void Mesh::draw(Transform modelToWorld,Material& material)
{
	glBindVertexArray(this->meshData->vertexArrayId);
	//glm::mat4 worldToView = Camera::getCamera()->worldToProjection(modelToWorld.modelTransformtionMatrix());

	//GLuint shaderProgramId = MaterialsManager::getMaterial(material);
	//glUseProgram(shaderProgramId);

	
	//GLint worldToViewLocation = glGetUniformLocation(shaderProgramId, "worldToView");
	//glUniformMatrix4fv(worldToViewLocation, 1, GL_FALSE, &worldToView[0][0]);

	//GLint modelToWorldLocation = glGetUniformLocation(shaderProgramId, "modelToWorld");
	//glUniformMatrix4fv(modelToWorldLocation, 1, GL_FALSE, &modelToWorld.modelTransformtionMatrix()[0][0]);

	//GLuint cameraWorldUniformLocation = glGetUniformLocation(shaderProgramId, "cameraWorld");
	//glUniform3fv(cameraWorldUniformLocation, 1, &Camera::getCamera()->position[0]);

	//GLuint anbientLightUniformLocation = glGetUniformLocation(shaderProgramId, "ambientLight");
	//glUniform3fv(anbientLightUniformLocation, 1, &Electron::ambientLight[0]);

	//DiffuseLightManager::addAttribs(shaderProgramId);
	
	glDrawElements(GL_TRIANGLES, meshData->numIndices, GL_UNSIGNED_SHORT, (void *)0);
}


void LineMesh::draw(Transform modelToWorld, Material& material)
{
	glBindVertexArray(this->meshData->vertexArrayId);
	glDrawElements(GL_LINES, meshData->numIndices, GL_UNSIGNED_SHORT, (void *)0);
}




