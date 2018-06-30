// leet_code_476_number_complement.cpp : Defines the entry point for the console application.
//

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

