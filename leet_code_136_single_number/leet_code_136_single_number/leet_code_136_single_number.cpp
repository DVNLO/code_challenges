/*
The following is a solution to prompt 136. Single Number 
from leetcode.com. The prompt can be found here: 
https://leetcode.com/problems/single-number/description/
I included a second solution found when reviewing the solution 
from leetcode.com. The use of XOR in this case simplifies 
the problem substantially, and leverages two properties of XOR
communatitive and A XOR A = 0. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
	//my solution beat 95%
	int singleNumber(std::vector<int>& nums) {
		int finalComparisonIndex = nums.size() - 2;
		std::sort(nums.begin(), nums.end()); //ascending order
		for (int i = 0; i < finalComparisonIndex; i += 2) {    //only even indexes
			if (nums[i] != nums[i + 1])
				return nums[i];
		}
		return nums[finalComparisonIndex + 1];	//must be the last element.
	}

	/*
	From leetcode.com. Leverages properties of XOR to find
	the single non-duplicate integer. A XOR A == 0.
	Therefore, A XOR B XOR A XOR B ... XOR Z == Z as Z is the
	single non-duplicate integer within the set. A more exact 
	explaination of the solution can be found here:
	https://leetcode.com/articles/single-number/
	*/
	int singleNumber_LC(std::vector<int>& nums) {
		int comparator = 0;
		for (int i = 0; i < nums.size(); i++) {
			comparator ^= nums[i];
		}
		return comparator;
	}
};

int main()
{
	Solution prompt;
	std::vector<int> nums = { 4,1,2,1,2 };
	std::cout << prompt.singleNumber(nums) << std::endl;
	std::cout << prompt.singleNumber_LC(nums) << std::endl;
    return 0;
}

