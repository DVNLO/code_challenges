/*
The following is a solution to prompt 283. Move Zeroes from leetcode.com
The prompt can be found here: https://leetcode.com/problems/move-zeroes/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <algorithm>
#include <vector>

class Solution {
public:
	/*
	Keep a "slow pointer" to move each non-zero
	element found when iterating through the array.
	Code found on leetcode.com: https://leetcode.com/articles/move-zeroes/
	Solution provides excellent example. 
	*/
	void moveZeroes(std::vector<int>& nums) {
		for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
			if (nums[cur] != 0) {
				std::swap(nums[lastNonZeroFoundAt++], nums[cur]);
			}
		}
	}

	/* My original solution. 26%
	void moveZeroes(vector<int>& nums) {
        int nums_size = nums.size();
        if(nums_size == 1)
            return;
        int non_zero_count = 0;
        for(int num : nums) {
            if(num)
                non_zero_count++;
        }
        int j = 0;
        int k;
        for(int i = 0; i < non_zero_count; i++){
            while(j < nums_size - 2 && nums[j])
                j++;
            k = j + 1;
            while(k < nums_size - 1 && !nums[k])
                k++;
            if(!nums[j] && nums[k])
                swap(nums[j], nums[k]);
        }
    }
	*/
};


int main()
{
	Solution prompt;
	std::vector<int> zeros = { 0,1,0,3,12 };
	prompt.moveZeroes(zeros);
    return 0;
}

