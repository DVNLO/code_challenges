/*
The following is a solution to prompt 784. Letter Case Permutation
from leetcode.com. The prompt can be found here: https://leetcode.com/problems/letter-case-permutation/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <string>
#include <vector>

class Solution {
public:
	char switchCase(const char& c) {
		if (c >= 'A' && c <= 'Z')
			return tolower(c);
		else
			return toupper(c);
	}

	std::vector<std::string> letterCasePermutation(std::string S) {
		std::vector<std::string> strings;
		strings.push_back(S);
		for (unsigned int i = 0; i < S.length(); i++) {
			if (isalpha(S[i])) {
				unsigned int stop = strings.size();
				for (unsigned int j = 0; j < stop; j++) {
					std::string s = strings[j];
					s[i] = switchCase(s[i]);
					strings.push_back(s);
				}
			}
		}
		return strings;
	}
};

int main()
{
	Solution prompt;
	prompt.letterCasePermutation("abcd");
    return 0;
}

