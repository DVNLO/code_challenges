/*
The following is a solution to prompt Two Sum from leetcode.com. The original 
prompt can be found here: https://leetcode.com/problems/two-sum/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> compliments;
		int nums_size = nums.size();
		for (int i = 0; i < nums_size; i++) {
			if (compliments.count(nums[i])) {
				return vector<int>{compliments.at(nums[i]), i};
			}
			else {
				compliments.insert({ target - nums[i], i });	//insert pair
			}
		}
	}
};

int main()
{
	vector<int> queries = { 2, 7, 11, 15 };
	Solution prompt;
	prompt.twoSum(queries, 9);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
