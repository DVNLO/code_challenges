/*
The following is a solution to prompt 496. Next Greater Element I from leetcode.com
The prompt can be found here: https://leetcode.com/problems/next-greater-element-i/description/
My solution utilizes linear search to locate an element num of findNums within nums.
While faster than 97% of submitted solutions, those 3% which were faster utilizes
an unordered_map to amortize lookup time. I have included an example solution 
utilizing an unordered_map as reference. Moreover, it should be noted, when a problem
potentially requires many lookups, such as this prompt, lookup tables are an 
effective means of minimizing search time.
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

class Solution {
public:
	std::vector<int> nextGreaterElement(std::vector<int>& findNums, std::vector<int>& nums) {
		int findNumsSize = findNums.size();
		int numsSize = nums.size();
		std::vector<int> nextGreaterNums(findNumsSize);
		for (int i = 0; i < findNumsSize; i++) {
			int num = findNums[i];
			int j = 0;  //nums index
			while (j < numsSize && num != nums[j])   //search for num
				j++;
			j++;    //move to the next index to compare
			while (j < numsSize && num >= nums[j])   //search for next greater
				j++;
			if (j != numsSize)   //next greater found
				nextGreaterNums[i] = nums[j];
			else
				nextGreaterNums[i] = -1;
		}
		return nextGreaterNums;
	}

	//example from leetcode utilizing a lookup unordered_map - well done. Not my code.
	std::vector<int> nextGreaterElementU_M(std::vector<int>& findNums, std::vector<int>& nums) {
		std::unordered_map<int, int> map;
		std::stack<int> st;
		for (int i = 0; i<nums.size(); i++) {
			while (!st.empty() && st.top()<nums[i]) {
				map[st.top()] = nums[i];
				st.pop();
			}
			st.push(nums[i]);
		}

		std::vector<int> res;
		for (int i = 0; i<findNums.size(); i++) {
			if (map.find(findNums[i]) == map.end()) {
				res.push_back(-1);
			}
			else
				res.push_back(map[findNums[i]]);
		}
		return res;
	}
};

int main()
{
	Solution prompt; 
	std::vector<int> findNums = {4,1,2};
	std::vector<int> nums = {1,3,4,2};
	std::vector<int> output = prompt.nextGreaterElement(findNums, nums);
	std::cout << "{ ";
	for (unsigned int i = 0; i < output.size(); i++) {
		std::cout << output[i] << " ";
	}
	std::cout << "}" << std::endl;
    return 0;
}

