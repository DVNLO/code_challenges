/*
The following is a solution to prompt 575. Distribute Candies from leetcode.com.
The prompt can be found here: https://leetcode.com/problems/distribute-candies/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <iostream>
#include <unordered_set>
#include <vector>

class Solution {
public:
	int distributeCandies(std::vector<int>& candies) {
		int candiesSize = candies.size();
		if (!candiesSize) return 0;
		int maxCount = candiesSize / 2;
		int sisters = 0;
		int i = 0;
		std::unordered_set<int> seen;
		std::pair<std::unordered_set<int>::iterator, bool> result;
		while (sisters < maxCount && i < candiesSize) {
			result = seen.emplace(candies[i]);
			if (result.second) {
				sisters++;
			}
			i++;
		}
		return sisters;
	}
};

int main()
{
	Solution prompt;
	std::vector<int> candies = { 1, 1, 2, 2, 3, 3 };
	std::cout << prompt.distributeCandies(candies) << std::endl;
    return 0;
}