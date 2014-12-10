#pragma once
#include <vector>

class StringUtils
{
public:
	StringUtils();
	~StringUtils();


	static std::vector<std::string> Split(const std::string &s, char delim);
	static bool startsWith(const std::string &source, const std::string &startsWith);
};

