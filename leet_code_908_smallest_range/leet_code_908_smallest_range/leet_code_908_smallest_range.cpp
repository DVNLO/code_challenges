/*
The following is a solution to leetcode prompt 908 smallest range.
I have included my original intuitive solution, as well as the uncommented
provided solution. Note how in the solution, we handle the case where
modification of min and max values overlap. If overlap is possible 
for the range, then we can get by without using my midpoint forumla. 
Original prompt: https://leetcode.com/problems/smallest-range-i/
Author: Dan Vyenielo
*/
#include "stdafx.h"
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	int smallestRangeI(vector<int>& A, int K) {
		int min_A = A[0];   // assumes A.size() > 0
		int max_A = min_A;
		for (const int val : A)
		{
			min_A = min(min_A, val);
			max_A = max(max_A, val);
		}
		// my original intuition
		//int midpoint = (min_A + max_A) / 2;
		//return ((max_A - min(max_A - midpoint, K)) - (min_A + min(midpoint - min_A, K)));
		return max(0, max_A - min_A - 2 * K);
	}
};

int main()
{
    return 0;
}

