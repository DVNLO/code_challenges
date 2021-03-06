/*
The following is a solution to prompt 258. Add Digits from leetcode.com.
The prompt can be found here: https://leetcode.com/problems/add-digits/hints/
I have included two solutions to the problem. My original solution
is commented out within addDigits(), and a solution from wikipedia
is provided known as the "digital root".
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/


#include "stdafx.h"

class Solution {
public:
	int addDigits(int num) {
		//https://en.wikipedia.org/wiki/Digital_root
		return 1 + ((num - 1) % 9);
		/*
		//naive solution
		int sumDigits;
		do {
		sumDigits = 0;
		while(num){
		sumDigits += num % 10;
		num /= 10;
		}
		num = sumDigits;
		} while(sumDigits > 9);
		return sumDigits;
		*/
	}
};


int main()
{
	Solution prompt;
	prompt.addDigits(2508);
    return 0;
}

