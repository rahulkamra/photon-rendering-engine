#include "Texture.h"


Texture::Texture(TextureData* textureData)
{
	this->textureData = textureData;
}
void Texture::bind(GLint samplerId)
{
	glActiveTexture(GL_TEXTURE + samplerId);
	glBindTexture(textureData->getTextureTarget(), textureData->getTextureObj());
}


Texture::~Texture()
{
}
