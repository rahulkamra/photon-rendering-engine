

struct Vector2
{
	Vector2(float x = 0.0f, float y = 0.0f) :x(x), y(y)
	{
	}

	float x, y;
};

Vector2 operator+(Vector2&lhs, Vector2&rhs)
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector2 operator-(Vector2&lhs, Vector2&rhs)
{
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

Vector2 operator*(float scaler, Vector2&rhs)
{
	return Vector2(scaler*rhs.x, scaler*rhs.y);
}

Vector2 operator*(Vector2&lhs, float scaler)
{
	return scaler * lhs;
}

Vector2 operator/(Vector2&lhs, float scaler)
{
	return Vector2(lhs.x/scaler, lhs.y/scaler);
}



