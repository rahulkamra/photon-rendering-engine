#include "StringUtils.h"
#include <boost\lexical_cast.hpp>
#include <boost/algorithm/string/predicate.hpp>

StringUtils::StringUtils()
{
}


StringUtils::~StringUtils()
{
}


std::vector<std::string> StringUtils::Split(const std::string& s, char delim)
{
	std::vector<std::string> elems;

	const char* cstr = s.c_str();
	unsigned int strLength = (unsigned int)s.length();
	unsigned int start = 0;
	unsigned int end = 0;

	while (end <= strLength)
	{
		while (end <= strLength)
		{
			if (cstr[end] == delim)
				break;
			end++;
		}

		elems.push_back(s.substr(start, end - start));
		start = end + 1;
		end = start;
	}

	return elems;
}


bool StringUtils::startsWith(const std::string &source, const std::string &startsWith)
{
	return boost::starts_with(source, startsWith);
}
