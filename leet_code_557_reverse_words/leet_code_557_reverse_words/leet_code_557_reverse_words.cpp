/*
The following is a solution to prompt 557. Reverse Words in a String III
from leetcode.com. Per the prompt's title, the function reverseWords()
reverses individual words within the input string s while maintaining
the original order of the words within the string. Verified. 
The prompt can be found here: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
Author: Dan vyenielo (dvyenielo@gmail.com)
Date: 30 June 2018
*/
#include "stdafx.h"
#include <string>
#include <iostream>

class Solution {
public:
	std::string reverseWords(std::string s) {
		int string_length = s.length();
		int left_index = 0;
		int right_index = 0;
		for (int i = 0; i < string_length; i++)
		{
			while (!(s[i] == ' ' || i == string_length))
				i++;
			right_index = i;
			for (int j = 0; j < (right_index - left_index) / 2; j++)
			{
				char temp = s[left_index + j];
				char right = s[right_index - j - 1];
				s[left_index + j] = right;
				s[right_index - j - 1] = temp;

			}
			if (i != string_length)
				left_index = i + 1;
		}
		return s;
	}
};

int main()
{
	Solution prompt;
	//"Let's take LeetCode contest"
	//"01234567890
	std::cout << prompt.reverseWords("Let's take LeetCode contest");
	int x;
	std::cin >> x;
    return 0;
}

