#include "TextureData.h"

const std::string TextureData::TYPE_RGBA = "RGBA";

TextureData::TextureData(std::string fileName, GLenum textureTarget, GLfloat filter)
{
	this->mTextureTarget = textureTarget;
	this->filter = filter;
	this->fileName = fileName;
}

bool TextureData::load()
{
	try
	{
		mImage = new Magick::Image(fileName);
		mImage->write(&mImageBlob, "RGBA");
	}
	catch (Magick::Error error)
	{
		std::cout << "Error loading texture '" << fileName << "': " << error.what() << std::endl;
		return false;
	}

	glGenTextures(1, &mTextureObj);
	glBindTexture(mTextureTarget, mTextureObj);
	glTexImage2D(mTextureTarget, 0, GL_RGBA, mImage->columns(), mImage->rows(), 0, GL_RGBA, GL_UNSIGNED_BYTE, mImageBlob.data());
	glTexParameterf(mTextureTarget, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(mTextureTarget, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return true;
}


GLenum TextureData::getTextureTarget()
{
	return mTextureTarget;
}
GLuint TextureData::getTextureObj()
{
	return mTextureObj;
}

TextureData::~TextureData()
{
}
