/*
The following is a solution to the prompt 561. Array Partition I from 
leetcode.com. You can find the prompt here: https://leetcode.com/problems/array-partition-i/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <vector>
#include <algorithm>

class Solution {
public:
	int arrayPairSum(std::vector<int>& nums) {
		std::sort(nums.begin(), nums.end());    //ascending
		int sum = 0;
		const int size = nums.size();
		for (int i = 0; i < size; i += 2)
			sum += nums[i]; //pair minimums at even indexes post sort().
		return sum;
	}
};

int main()
{
	Solution prompt;
	std::vector<int> nums { 1, 4, 3, 2 };
	prompt.arrayPairSum(nums);
    return 0;
}

