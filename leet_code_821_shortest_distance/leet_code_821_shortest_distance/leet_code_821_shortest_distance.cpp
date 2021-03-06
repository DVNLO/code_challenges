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
		std::vector<int> shortestDistances(string_length, -1);
		int cursor_index = 0;
		for (int i = 0; i < string_length; i++)
		{
			if (S[i] == C)
			{
				shortestDistances[i] = 0;
				int left_distance = 1;
				int left_focus = i - left_distance;
				while (left_focus >= 0 && S[left_focus] != C)
				{
					if (left_distance < shortestDistances[left_focus] || shortestDistances[left_focus] == -1)
					{
						shortestDistances[left_focus] = left_distance;
					}
					left_distance++;
					left_focus = i - left_distance;
				}
				int right_distance = 1;
				int right_focus = i + right_distance;
				while (right_focus < string_length && S[right_focus] != C)
				{
					if (right_distance < shortestDistances[right_focus] || shortestDistances[right_focus] == -1)
					{
						shortestDistances[right_focus] = right_distance;
					}
					right_distance++;
					right_focus = i + right_distance;
				}
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

