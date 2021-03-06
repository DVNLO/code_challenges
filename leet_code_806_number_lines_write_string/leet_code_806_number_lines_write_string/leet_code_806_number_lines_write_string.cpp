/*
The following is a solution to prompt 806. Number of Lines To Write String
from leetcode.com. The prompt is available here: https://leetcode.com/problems/number-of-lines-to-write-string/description/
Author: Dan Vyenielo dvyenielo@gmail.com
Date: 28 June 2018
*/

#include "stdafx.h"
#include <string>
#include <vector>

class Solution {
public:
	std::vector<int> numberOfLines(std::vector<int>& widths, std::string S) {
		const int max_line_width = 100;
		std::vector<int> lines;
		lines.reserve(2);
		int charWidth;
		int lineWidth = 0;
		int lineCount = 1;  //S cannot be null;
		for (char c : S)
		{
			charWidth = widths[c - 'a'];    //S only contains lowercase
			if (charWidth + lineWidth > max_line_width)
			{
				lineCount++;
				lineWidth = charWidth;
			}
			else
			{
				lineWidth += charWidth;
			}
		}
		lines.emplace_back(lineCount);
		lines.emplace_back(lineWidth);
		return lines;
	}
};


int main()
{
	Solution prompt;
	std::vector<int>widths = { 4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };
	std::string S = "bbbcccdddaaa";
	prompt.numberOfLines(widths, S);
    return 0;
}

