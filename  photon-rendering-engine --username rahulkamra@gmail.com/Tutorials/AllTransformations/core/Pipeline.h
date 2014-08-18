#pragma once
#include <Header.h>

class Pipeline
{
private:
	Vector3f mScale;
	Vector3f mRotate;
	Vector3f mPosition;

	Vector3f m_worldPos;
	void initScale(Matrix4f &m) const;
	void initRotate(Matrix4f &m) const;
	void initTranslate(Matrix4f &m) const;

	void InitTranslationTransform(Matrix4f& m) const;
public:

	Pipeline()
	{

	}

	~Pipeline()
	{

	}
};

