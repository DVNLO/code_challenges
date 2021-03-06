/*
The following is a solution to prompt 868. Binary Gap
from leetcode.com. The prompt can be found here:
https://leetcode.com/problems/binary-gap/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"

class Solution {
public:
	// The following is a revised version of my original solution. 
	// I am very much enjoying reviewing code I wrote a couple 
	// years ago. It's helpful to see these improvements, and I feel 
	// it lends credability to my experience over the last couple years.  
	int binaryGap_1(int N) 
        {
            static size_t constexpr BITS_PER_BYTE{ 8 };
            static size_t constexpr BIT_COUNT{ sizeof(int) * BITS_PER_BYTE };
            size_t l{ 0 };
            int gap_distance{ 0 };
            int max_gap_distance{ 0 };
            unsigned bit_mask{ 0x1 };
            while(l < BIT_COUNT)
            {
                if(bit_mask & N)
                {
                    gap_distance = 0;
                    do
                    {
                        bit_mask <<= 1;
                        ++l;
                        ++gap_distance;
                    }
                    while(l < BIT_COUNT
                           && !(bit_mask & N));
                    if(bit_mask & N 
                       && gap_distance > max_gap_distance)
                        max_gap_distance = gap_distance;
                }
                else
                {
                    ++l;
                    bit_mask <<= 1;
                }
            }
            return max_gap_distance;
        }
	
	
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

