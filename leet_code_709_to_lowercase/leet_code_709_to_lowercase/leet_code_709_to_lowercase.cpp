/*
The following is a solution to prompt 709. To Lower Case from 
leetcode.com. The prompt can be found here: https://leetcode.com/problems/to-lower-case/description/
My solution utilizes a linear search to find characters
within an input string str. When an uppercase character c is found 
the character is converted to lower case via bitwise or.
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <iostream>
#include <string>

class Solution {
public:
	std::string toLowerCase(std::string str) {
		for (int i = 0; i < str.length(); i++) {
			char* c = &str[i];
			if (*c >= 'A' && *c <= 'Z')
				*c |= 0x20;
		}
		return str;
	}
};

int main()
{
	Solution prompt;
	std::cout << prompt.toLowerCase("Hello") << std::endl;
    return 0;
}

