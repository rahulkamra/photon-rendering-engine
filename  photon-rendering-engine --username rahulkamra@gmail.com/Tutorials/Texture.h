#pragma once
#include<TextureData.h>
class Texture
{
private:
	TextureData* textureData;

public:
	Texture(TextureData* textureData);
	void bind(GLint samplerId);
	~Texture();
};

