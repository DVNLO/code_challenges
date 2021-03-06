/*
The following is a solution to prompt 521. Longest Uncommon Subsequence I
from leetcode.com. The prompt can be found here: 
https://leetcode.com/problems/longest-uncommon-subsequence-i/description/
I spent a long time attempting to solve this problem by iteratively 
forming all possible substrings of lesser lengths. My commented 
out code can successfully check all intermitent combinations,
but the problem is much simplier. 
The solution is posted here:
https://leetcode.com/articles/longest-uncommon-subsequence-i/
Remember that a string a that is longer than another string
cannot be a substring of the other. ie: len(A) > len(B) implies
that the sequence of A is uncommon to B as B cannot possibly form
A. Consequence of set logic from maths!
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
	int findLUSlength(std::string a, std::string b) {
		if (a == b)
			return -1;
		else
			return std::max(a.length(), b.length());
		
		/*
		unordered_set<string> combinations;
		combinations.emplace(a);
		for (int i = 0; i < a.size(); i++) {
			vector<string> substrs;
			for (string str : combinations) {
				std::size_t found = b.find(str);
				if (found == std::string::npos)
					return a.size() - i;
				combinations.erase(str);
				substrs.emplace_back(str);
			}
			for (string str : substrs) {
				for (int j = 0; j < str.size(); j++) {
					int k = 0;
					string substr = "";
					while (k < j) {  //left
						substr += str[k];
						k++;
					}
					k++;
					while (k < str.size()) { //right
						substr += str[k];
						k++;
					}
					combinations.emplace(substr);
				}
			}
		}
		return -1;
		*/
	}
};


int main()
{
	Solution prompt;
	prompt.findLUSlength("abc", "abcxyz");
    return 0;
}

