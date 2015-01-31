#pragma once
#include <gtest\gtest.h>
#include <Matrix2D.h>

using namespace math;


TEST(Matrix2D, MultiplyWithVector)
{
	Matrix2D matrix(2, -3, 
					4, 5);
	Vector2D vec2(3, 9);

	Vector2D result = matrix*vec2; 

	

	EXPECT_TRUE(result.x == -21 && result.y == 57);
}