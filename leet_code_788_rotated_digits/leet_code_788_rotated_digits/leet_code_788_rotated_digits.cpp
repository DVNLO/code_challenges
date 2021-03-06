/*
The following is a solution to prompt 788. Rotated Digits from leetcode.com
The prompt can be found here : https://leetcode.com/problems/rotated-digits/description/
Author: Dan Vyeniel (dvyenielO@gmail.com)
I have included two solutions. The first, commented out, was my initial 
implementation. It was inefficient, but accepted. The inefficiency
stemmed from failing to see a simplification which could be introduced.
To simplify, I simply noted "if a valid number 2, 5, 6, and/or 9"
is present in the original number. If one of these digits is present 
and the number does not contain 3, 4, or 7 then the digit is valid. 
0, 1, and 8 do not map to themselves. 
There were some interesting dynamic programming solutions to this
problem available in the discussion section, mainly:
https://leetcode.com/problems/rotated-digits/discuss/117975/Java-dp-solution-9ms
While difficult to understand from a coding standpoint, they
do provide an insightful approach. 
*/
#include "stdafx.h"

class Solution {
public:
	bool canRotate(const int& n) {
		int copy = n;
		bool hasValid = false;
		while (copy) {
			switch (copy % 10) {
			case 2:
			case 5:
			case 6:
			case 9:
				hasValid = true;
				break;
			case 3:
			case 4:
			case 7:
				return false;
			}
			copy /= 10;
		};
		return hasValid;
	}

	/* Note: there is no need to accumulate. If n
	contains 2,5,6 and/or 9 then it is valid.
	bool canRotate(const int& n) {
        int copy = n;
        int accumulator = 0;
        int power = 1;
        while(copy){
            int remainder = copy % 10;
            switch(remainder) {
                case 2:
                    remainder = 5;
                    break;
                case 5:
                    remainder = 2;
                    break;
                case 6:
                    remainder = 9;
                    break;
                case 9:
                    remainder = 6;
                    break;
                case 3: 
                case 4: 
                case 7:
                    return false;
            }
            accumulator += remainder * power;
            power *= 10;
            copy /= 10;
        };
        return accumulator != n;
    }
	*/

	int rotatedDigits(int N) {
		int rotate_count = 0;
		for (int i = 1; i <= N; i++) {
			if (canRotate(i))
				rotate_count++;
		}
		return rotate_count;
	}
};


int main()
{
    return 0;
}

