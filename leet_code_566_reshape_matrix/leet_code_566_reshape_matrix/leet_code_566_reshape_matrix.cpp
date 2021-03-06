/*
The following is a solution to prompt 566. Reshape the Matrix from leetcode.com.
The prompt can be found here: https://leetcode.com/problems/reshape-the-matrix/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <vector>
#include <iostream>

class Solution {
public:
	std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& nums, int r, int c) {
		int og_r = nums.size(); //original rows
		if (!og_r)
			return nums;
		int og_c = nums[0].size();  //original columns
		if (!og_c)
			return nums;
		if (og_r * og_c < r * c)
			return nums;
		std::vector<std::vector<int>> reshaped_nums(r, std::vector<int>(c));
		for (int i = 0; i < og_r; i++) {
			for (int j = 0; j < og_c; j++) {
				int og_count = i * og_c + j;
				reshaped_nums[og_count / c][og_count % c] = nums[i][j];
			}
		}
		return reshaped_nums;
	}
};

int main()
{
	Solution prompt;
	std::vector<std::vector<int>> input = { {1,2},{3,4} };
	std::vector<std::vector<int>> output = prompt.matrixReshape(input, 1, 4);
	std::cout << "{ ";
	for (unsigned int i = 0; i < output.size(); i++) {
		std::cout << "{ ";
		for (unsigned int j = 0; j < output[0].size(); j++) {
			std::cout << output[i][j] << " ";
		}
		std::cout << "}";
	}
	std::cout << " }" << std::endl;
    return 0;
}

