#pragma once
#include <src\gtest-all.cc>
#include <stdio.h>
int main(int argc , char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::cin.get();
}