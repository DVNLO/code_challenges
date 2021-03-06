// leet_code_917_reverse_only_letters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>

class Solution {
public:
	//index pointer based solution
	std::string reverseOnlyLetters_indexs(std::string S) {
		int left = 0;
		int right = S.size() - 1;
		while (left < right) {	//in the empty case left = 0 and right = -1, left < right == false -> return S;
			while (left < right && !isalpha(S[left])) {
				left++;
			}
			while (right > left && !isalpha(S[right])) {
				right--;
			}
			std::swap(S[left], S[right]);
			left++;
			right--;
		}
		return S;
	}
	
	//real pointer based solution
	std::string reverseOnlyLetters_ptrs(std::string S) {
		if (S.empty()) {
			return S;
		}
		char* left = &S[0];
		char* right = &S[S.size() - 1];
		while (left < right) {
			while (left < right && !isalpha(*left))
				left++;
			while (right > left && !isalpha(*right))
				right--;
			std::swap(*left, *right);
			left++;
			right--;
		}
		return S;
	}
};

int main() {
	std::string test = "a-bC-dEf-ghIj";
	Solution prompt;
	std::string res = prompt.reverseOnlyLetters(test);
	std::cout << res;
}

/* From leetcode
std::string stringToString(std::string input) {
	assert(input.length() >= 2);
	std::string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}
*/

/* from leetcode
int main() {
	std::string line;
	while (std::getline(std::cin, line)) {
		std::string S = stringToString(line);

		std::string ret = Solution().reverseOnlyLetters(S);

		std::string out = (ret);
		std::cout << out << std::endl;
	}
	return 0;
}
*/