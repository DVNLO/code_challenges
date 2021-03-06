/*
The following is a solution to prompt824. Goat Latin from leetcode.com.
The prompt can be found here: https://leetcode.com/problems/goat-latin/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <string>
#include <vector>

class Solution {
public:
	std::string toGoatLatin(std::string S) {
		std::vector<std::string> words;
		int left_index = 0;
		for (int i = 0; i < S.length(); i++) {
			while (i < S.length() && S[i] != ' ')
				i++;
			words.push_back(S.substr(left_index, i - left_index));
			left_index = i + 1;
		}
		const std::string ma = "ma";
		std::string a_s = "a";
		for (int i = 0; i < words.size(); i++) {
			char c = words[i][0];
			switch (c) {
				case 'A': case 'a':
				case 'E': case 'e':
				case 'I': case 'i':
				case 'O': case 'o':
				case 'U': case 'u':
					words[i] += ma;   //append ma
					break;
				default:
					words[i] = words[i].substr(1) + c + ma;  //move first char to the end then append ma
			}
			words[i] += a_s;
			a_s += "a";
		}
		std::string result = words[0];
		int j = 1;
		while (j < words.size()) {	//build result string
			result += " " + words[j];
			j++;
		}
		return result;
	}
};

int main()
{
	Solution prompt;
	prompt.toGoatLatin("I speak Goat Latin");
    return 0;
}

