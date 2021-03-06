/*
The following are solutions to prompt 693. Binary Number with Alternating Bits
from leetcode.com. The first solution, is my solution. It utilizes the 
division algothim to repeatedly find a quotient via modulo arithmetic.
The function returns false when two adjacent bits are equivalent.
The second solution I found when reviewing the discussion threads
on leetcode.com and utilizes bit shift operations to determine 
if the bits of n are alternating.
The prompt can be found here: https://leetcode.com/problems/binary-number-with-alternating-bits/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <iostream>

class Solution {
public:
	//my solution
	bool hasAlternatingBits(int n) {
		int remainder = n % 2;
		int quotient = n / 2;
		while (quotient) {
			int next_remainder = quotient % 2;
			if (next_remainder == remainder)
				return false;
			quotient /= 2;
			remainder = next_remainder;
		}
		return true;
	}
	
	/*
	interesting solution from leetcode.com discussion:
	https://leetcode.com/problems/binary-number-with-alternating-bits/discuss/108447/JavaC++-Very-simple-solution-1-line
	*/
	bool hasAlternatingBits_discuss(int n) {
		return ((long(n) + (n >> 1) + 1) & (long(n) + (n >> 1))) == 0;
	}

};

int main()
{
	Solution prompt;
	std::cout << prompt.hasAlternatingBits(5) << std::endl;
    return 0;
}

