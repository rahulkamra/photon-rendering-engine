#pragma once
#include <string>
#include <GL\glew.h>
#include <glm\gtc\matrix_transform.hpp>
#include <Common\GameObj\Transform.h>
#include <Texture.h>

class Shader
{

private :
	GLuint shaderId;
public:
	void addMat4(std::string name, glm::mat4 matrix);
	void addVec3(std::string name, glm::vec3 vector);
	void  addFloat(std::string name, float value);
	void addTextureUniform(std::string name, GLuint samplerId);
	GLuint getShaderId();

	std::map<std::string, Texture*> m_textureMap;

	inline void AddTexture(const std::string& name, Texture* value);
	void bind();
	
	inline Texture* GetTexture(const std::string& name) const;
	
	Shader(std::string fileName);
	~Shader();
};

