/*
The following is a solution to prompt 448. Find All Numbers Disappeared in an Array
from leetcode.com. The prompt can be found here: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
I have provided two solutions, my original solution. It's currently
commented out. And, a solution which I found on the discussion section. 
The discussion code utilizes properties of the input domain
to negate the values of the corresponding index position 
to the values found in the first walk of the original array. 
This strategy negates the index positions that are present 
in the original array, leaving the index positions which 
are not found in the original array greater than 0. Excellent solution.
Author: Dan Vyeniel (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <vector>

class Solution {
public:
	std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
		//my code, not my idea. Original credit: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/92956/Java-accepted-simple-solution
		int size = nums.size();
		for (int i = 0; i < size; i++) {
			int index = abs(nums[i]) - 1;
			if (nums[index] > 0) {
				nums[index] = -nums[index];
			}
		}
		std::vector<int> holes;
		for (int j = 0; j < size; j++) {
			if (nums[j] > 0)
				holes.push_back(j + 1);
		}
		return holes;

		//original solution beat 8%
		/*
		int size = nums.size();
		unordered_set<int> s;
		for(int i = 1; i <= size; i++)
		s.insert(i);
		for(int j = 0; j < size; j++) {
		int value = nums[j];
		if(s.count(value))
		s.erase(value);
		}
		vector<int> output(s.begin(), s.end()); //range based constructor
		return output;
		*/
	}
};

int main()
{
	Solution prompt;
	std::vector<int> nums = { 4, 3, 2, 7, 8, 2, 3, 1 };
	prompt.findDisappearedNumbers(nums);
    return 0;
}

