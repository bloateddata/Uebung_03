#pragma once
#include <iostream>
#include <vector>

std::vector<std::string> Split_String(std::string s)
{
	std::vector<std::string> sv;
	std::string temp;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != '\n')
		{
			temp += s[i];
		}
		else
		{
			sv.push_back(temp);
			temp.clear();
		}
	}

	return sv;
}