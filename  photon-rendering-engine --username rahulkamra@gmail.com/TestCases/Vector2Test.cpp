#pragma once
#include <gtest\gtest.h>
#include <Vector2.h>

TEST(Vector2 , Add)
{
	Vector2 vec1(2, 5);
	Vector2 vec2(3, 6);

	Vector2 result(vec1.x + vec2.x, vec1.y + vec2.y);
	Vector2 result1 = vec1 + vec2;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}

TEST(Vector2, Subtract)
{
	Vector2 vec1(2, 5);
	Vector2 vec2(3, 6);

	Vector2 result(vec1.x - vec2.x, vec1.y - vec2.y);
	Vector2 result1 = vec1 - vec2;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}




TEST(Vector2, Multiply)
{
	Vector2 vec1(2, 5);
	float scaler = 2.0f;

	Vector2 result(vec1.x * scaler, vec1.y *scaler);
	Vector2 result1 = vec1 * scaler;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}





TEST(Vector2, Divide)
{
	Vector2 vec1(2, 5);
	float scaler = 2.0f;

	Vector2 result(vec1.x / scaler, vec1.y /scaler);
	Vector2 result1 = vec1 / scaler;

	EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}
