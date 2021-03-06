/*
The following is a solution to prompt 520. Detect Capital from leetcode.com
The prompt can be found here: https://leetcode.com/problems/detect-capital/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
The following is a simple program to determine the "capital" case
from the prompt. 
*/
#include "stdafx.h"
#include <cctype>
#include <string>

class Solution {
public:
	bool detectCapitalUse(std::string word) {
		int word_length = word.length();
		if (isupper(word[0])) {
			if (isupper(word[1])) {  //all capital
				int i = 2;
				while (i < word_length) {
					if (!isupper(word[i]))
						return false;
					i++;
				}
			}
			else {    //one capital
				int i = 1;
				while (i < word_length) {
					if (isupper(word[i]))
						return false;
					i++;
				}
			}
		}
		else {    //no capital
			int i = 1;
			while (i < word_length) {
				if (isupper(word[i]))
					return false;
				i++;
			}
		}
		return true;
	}
};

int main()
{
	Solution prompt;
	prompt.detectCapitalUse("Dingus");
    return 0;
}

