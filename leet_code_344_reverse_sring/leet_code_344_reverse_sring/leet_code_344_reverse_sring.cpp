/*
The following is a solution to prompt 344. Reverse String from leetcode.com.
Per the prompmt title, this program reverses an input string by swapping 
characters within an input string around the central character.
The leetcode prompt can be found here: https://leetcode.com/problems/reverse-string/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
Date: 30 June 2018
*/

#include "stdafx.h"
#include <string>
#include <iostream>

class Solution {
public:
	std::string reverseString(std::string s) {
		int final_index = s.length();
		for (int i = 0; i < final_index / 2; i++)
		{
			char front = s[i];
			char back = s[final_index - i - 1];
			s[final_index - i - 1] = front;
			s[i] = back;
		}
		return s;
	}
};

int main()
{
	Solution prompt;
	std::cout << prompt.reverseString("hello");
	int x;
	std::cin >> x;
    return 0;
}

