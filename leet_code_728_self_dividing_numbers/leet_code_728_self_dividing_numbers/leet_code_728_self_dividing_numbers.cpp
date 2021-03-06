/*
The following is a solution to a prompt provided by leetcode.com.
The prompt, 728. Self Dividing Numbers, asks the user to implement a function
for finding self-dividing numbers within an inclusive range. 
A self-dividing number is defined being divisible by all composing digits.
The prompt is available here: https://leetcode.com/problems/self-dividing-numbers/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
Date: 28 June 2018
*/

#include "stdafx.h"
#include <vector>

class Solution {
public:
	std::vector<int> selfDividingNumbers(int left, int right) {
		std::vector<int> selfDividers;
		bool isSelfDividing;
		int number;
		int remainder;
		while (left <= right)
		{
			isSelfDividing = true;
			number = left;
			while (!(number == 0 || !isSelfDividing))
			{
				remainder = number % 10;
				isSelfDividing = !((remainder == 0) || (left % remainder != 0));
				number /= 10;
			}
			if (isSelfDividing)
				selfDividers.push_back(left);
			left++;
		}
		return selfDividers;
	}
};

int main()
{
	Solution prompt;
	prompt.selfDividingNumbers(1, 22);
    return 0;
}

