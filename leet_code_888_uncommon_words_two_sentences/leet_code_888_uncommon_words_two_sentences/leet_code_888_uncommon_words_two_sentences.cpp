/*
The following is a solution to prompt 888. Uncommon Words from Two Sentences
from leetcode.com. The prompt is available here:
https://leetcode.com/problems/uncommon-words-from-two-sentences/description/
Author : Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
private:
	void processUncommonWord(const std::string& word, std::unordered_map<std::string, int>& words) {
		if (words.count(word)) {
			words[word]++;
		} else {
			words.emplace(word, 1);
		}
	}

	void processUncommonString(const std::string& S, std::unordered_map<std::string, int>& words) {
		std::string word = "";
		int length = S.length();
		int terminal_index = length - 1;
		for (int i = 0; i < length; i++) {
			char c = S[i];
			if (c == ' ') {
				processUncommonWord(word, words);
				word = "";
			}
			else
				word += c;
		}
		processUncommonWord(word, words);
	}

public:
	std::vector<std::string> uncommonFromSentences(std::string A, std::string B) {
		std::unordered_map<std::string, int> words;
		processUncommonString(A, words);
		processUncommonString(B, words);
		std::vector<std::string> uncommon_words;
		for (const auto& word : words) {
			if (word.second == 1) {
				uncommon_words.emplace_back(word.first);
			}
		}
		return uncommon_words;
	}
};


int main()
{
	Solution prompt;
	std::vector<std::string> result = prompt.uncommonFromSentences("this apple is sweet", "this apple is sour");
	for (const auto& word : result) {
		std::cout << word << std::endl;
	}
	return 0;
}

