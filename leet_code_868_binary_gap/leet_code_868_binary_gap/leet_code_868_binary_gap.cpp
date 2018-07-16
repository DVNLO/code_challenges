/*
The following is a solution to prompt 868. Binary Gap
from leetcode.com. The prompt can be found here:
https://leetcode.com/problems/binary-gap/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"

class Solution {
public:
	int binaryGap(int N) {
		int mask = 0x1; //0000 .... 0001;
		int i = 0;
		while (!(N & mask) && N) {   //find index of first 1
			N >>= 1;
			i++;
		}
		if (!(N & mask)) //no 1 found 
			return 0;
		int right = i; // save index of 1
		N >>= 1;    //move to the next index
		i++;
		int maxDistance = 0;
		while (N) {  //search for max distance while N != 0
			if ((N & mask)) {
				int distance = i - right;
				if (distance > maxDistance) {
					maxDistance = distance;
				}
				right = i;
			}
			N >>= 1;
			i++;
		}
		return maxDistance;
	}
};

int main()
{
	Solution prompt;
	prompt.binaryGap(22);
    return 0;
}

