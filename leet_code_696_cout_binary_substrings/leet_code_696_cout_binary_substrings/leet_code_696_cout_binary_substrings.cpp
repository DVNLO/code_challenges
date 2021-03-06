/*
The following is not a solution to prompt 696. Count Binary Substrings
from leetcode.com. The prompt can be found here: https://leetcode.com/problems/count-binary-substrings/description/
My solution was not accepted due to timeout. Will revisit at a 
later date to develop a more efficient algorithm. 
*/

#include "stdafx.h"
#include <string>

class Solution {
public:
	int countBinarySubstrings(std::string s) {
		int substr_count = 0;
		int str_length = s.length();
		int final_index = str_length - 1;
		for (int i = 0; i < final_index; i++) {
			char left = s[i];
			int j = i + 1;
			int symmetric_count = 0;
			while (j < str_length && left == s[j]) {
				symmetric_count++;
				j++;
			}
			left = s[j];
			j++;
			while (j < str_length && symmetric_count && left == s[j]) {
				symmetric_count--;
				j++;
			}
			if (!symmetric_count)
				substr_count++;
		}
		return substr_count;
	}
};

int main()
{
	Solution prompt;
	prompt.countBinarySubstrings("00110011");
    return 0;
}

