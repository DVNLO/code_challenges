/*
The following is a solution to prompt 389. Find the Difference 
from leetcode.com. The prompt can be found here:
https://leetcode.com/problems/find-the-difference/description/
My original solution relied on sorting the input strings s and t,
then iterated through each position of s searching for a corresponding 
character in t at the same index. The non-equal character or the last
character in t is returned. Unfortunately, this algorithm is 
inefficient. As in an older problem (https://leetcode.com/problems/single-number/description/)
XOR can be employeed here to find the different character. 
Since only a single character differs between s and t
the XOR of all characters in s+t will return the different character.
Note "one or the other, but not both" when asked 
to find differences in strings. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <string>

class Solution {
public:
	char findTheDifference(std::string s, std::string t) {
		std::string st = s + t;
		char r = 0;
		for (char c : st)
			r ^= c;
		return r;

		/* //original solution
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		for(int i = 0; i < s.length(); i++) {
		if(s[i] != t[i])
		return t[i];
		}
		return t[t.length() - 1];
		*/
	}
};

int main()
{
	Solution prompt;
	prompt.findTheDifference("dan", "danm");
    return 0;
}

