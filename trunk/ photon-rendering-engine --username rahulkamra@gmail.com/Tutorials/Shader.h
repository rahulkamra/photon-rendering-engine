#pragma once
#include <string>
#include <GL\glew.h>
#include <glm\gtc\matrix_transform.hpp>
#include <Common\GameObj\Transform.h>
#include <Texture.h>

class Shader
{

private :
	ShaderData* shaderData;
public:
	void addMat4(std::string name, glm::mat4 matrix);
	void addVec3(std::string name, glm::vec3 vector);
	void addFloat(std::string name, float value);
	void addTexture(std::string name, Texture* texture);
	GLuint getShaderId();

	

	
	void bind();
	
	Shader(std::string fileName);
	~Shader();
};

