#pragma once
#include <string>
#include <iostream>
#include "Magick++.h"
#include <GL/glew.h>
class TextureData
{
private :
	Magick::Image* mImage;
	Magick::Blob mImageBlob;
	GLuint mTextureObj;
	GLenum mTextureTarget;
	GLfloat filter;
	std::string fileName;

public:
	TextureData(std::string fileName, GLenum textureTarget = GL_TEXTURE_2D, GLfloat filter = GL_LINEAR);
	bool load();
	~TextureData();
	GLenum getTextureTarget();
	GLuint getTextureObj();



	static const std::string TYPE_RGBA;

};

