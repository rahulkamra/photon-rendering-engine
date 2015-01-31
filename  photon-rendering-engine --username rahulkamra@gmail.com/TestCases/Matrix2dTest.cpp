#pragma once
#include <gtest\gtest.h>
#include <Matrix2D.h>

using namespace math;


TEST(Matrix2D, MultiplyWithVector)
{
	Matrix2D matrix(10, 2, 3, 1);
	Vector2D vec2(3, 6);

	Vector2D result = matrix*vec2; 

	

	//EXPECT_TRUE(result.x == result1.x && result.y == result1.y);
}