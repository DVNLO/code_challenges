/*
The following is a solution to Prompt 804: Unique Morse Code Words provided by 
leetcode.com.
Author: Dan Vyenielo*/
#include "stdafx.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

const static std::unordered_map<char, std::string> CHAR_TO_MORSE_MAP = { { 'a', ".-" },{ 'b', "-..." },{ 'c', "-.-." },{ 'd', "-.." },{ 'e', "." },{ 'f', "..-." },{ 'g', "--." },{ 'h', "...." },{ 'i', ".." },{ 'j', ".---" },{ 'k', "-.-" },{ 'l', ".-.." },{ 'm', "--" },{ 'n', "-." },{ 'o', "---" },{ 'p', ".--." },{ 'q', "--.-" },{ 'r', ".-." },{ 's', "..." },{ 't', "-" },{ 'u', "..-" },{ 'v', "...-" },{ 'w', ".--" },{ 'x', "-..-" },{ 'y', "-.--" },{ 'z', "--.." } };

/*
Returns the number of unique morse code transformations for strings within words.
Example (from leetcode.com):
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
*/
int uniqueMorseRepresentations(std::vector<std::string>& words)
{
	std::unordered_set<std::string> morse_words;
	for (const std::string word : words)
	{
		std::string morse_word; 
		for (const char letter : word)
		{
			auto itr = CHAR_TO_MORSE_MAP.find(letter);
			if (itr != CHAR_TO_MORSE_MAP.end())
			{
				morse_word.append(itr->second);
			}
		}
		morse_words.insert(morse_word);
	}
	return morse_words.size();
}

int main()
{
	std::vector<std::string> words = { "gin", "zen", "gig", "msg" };
	std::cout << uniqueMorseRepresentations(words) << std::endl;
    return 0;
}

