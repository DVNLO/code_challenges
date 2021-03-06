// binary_strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>

std::vector<std::vector<std::string>> all_binary_strings_of_length_n(int n)
{
	std::vector<std::vector<std::string>> root = { {"0"}, {"1"} };
	for (int j = 0; j < n; j++)
	{
		//for 0
		for (int k = 0; k < j; k++)
		{
			std::string in0 = root.at(j).at(k);
			std::string in1 = in0;
			in0 += "0";
			in1 += "1";
			root.at(j).push_back(in0);
			root.at(j).push_back(in1);
		}

		//for 1
		root.at(j + 1);
		for (int k = 1; k < j + 1; k++)
		{
			std::string in0 = root.at(j + 1).at(k - 1);
			std::string in1 = in0;
			in0 += "0";
			in1 += "1";
			root.at(j).push_back(in0);
			root.at(j).push_back(in1);
		}
	}
	return root;
}


int main()
{
	all_binary_strings_of_length_n(2);
    return 0;
}

