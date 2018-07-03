// leet_code_821_shortest_distance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
	std::vector<int> shortestToChar(std::string S, char C) {
		int string_length = S.length();
		std::vector<int> shortestDistances(string_length, 0);
		int left_index = 0;
		int right_index = 0;
		for (int i = 0; i < string_length; i++)
		{
			while (S[i] != C && i < string_length)
				i++;
			right_index = i;
			i = right_index - left_index;
			for (int j = left_index; j < right_index; j++)
				shortestDistances[j] = i--;	//assign then decrement.
			if (right_index != string_length)
			{
				i = right_index + 1;
				left_index = i;
			}
		}
		return shortestDistances;
	}
};

int main()
{
	Solution prompt;
	std::vector<int> result = prompt.shortestToChar("loveleetcode", 'e');
	for (int i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << ", ";
	}
    return 0;
}

