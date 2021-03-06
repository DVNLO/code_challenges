/*
The following is a solution to prompt: 476. Number Complement from leetcode.com.
The prompt can be found here: https://leetcode.com/problems/number-complement/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"

class Solution {
public:
	int findComplement(int num) {
		int temp = num;
		int mask = 1;
		while (temp != 0)
		{
			mask <<= 1;
			temp >>= 1;
		}
		return num ^ (mask - 1);    //to get 111...1 mask
	}
};

int main()
{
	Solution prompt;
	int output = prompt.findComplement(5);
    return 0;
}

