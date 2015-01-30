#pragma once;

#include "MathDefine.h"
  
struct Vector2 
{
	Vector2(efloat x = 0.0f, efloat y = 0.0f) :x(x), y(y)
	{
	}
	 
	efloat x, y;


	efloat dot(Vector2* rhs)
	{
		return this->x * rhs->x +  this->y * rhs->y;
	}



};

Vector2 operator+(Vector2&lhs, Vector2&rhs)
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector2 operator-(Vector2&lhs, Vector2&rhs)
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

Vector2 operator*(efloat scaler, Vector2&rhs)
{
	return Vector2(scaler*rhs.x, scaler*rhs.y);
}

Vector2 operator*(Vector2&lhs, efloat scaler)
{
	return scaler * lhs;
}

Vector2 operator/(Vector2&lhs, efloat scaler)
{
	return Vector2(lhs.x/scaler, lhs.y/scaler);
}



