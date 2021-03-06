/*
The following is a solution to prompt 485. Max Consecutive Ones from leetcode.com
The prompt can be found here: https://leetcode.com/problems/max-consecutive-ones/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <vector>

class Solution {
public:
	int findMaxConsecutiveOnes(std::vector<int>& nums) {
		int consecutiveCount = 0;
		int maxConsecutiveCount = 0;
		int i = 0;
		while (i < nums.size()) {
			if (nums[i]) {
				consecutiveCount++;
				if (consecutiveCount > maxConsecutiveCount)
					maxConsecutiveCount = consecutiveCount;
			}
			else
				consecutiveCount = 0;
			i++;
		}
		return maxConsecutiveCount;
	}
};

int main()
{
	Solution prompt;
	std::vector<int> digits = { 1,1,0,1,1,1 };
	prompt.findMaxConsecutiveOnes(digits);
    return 0;
}

