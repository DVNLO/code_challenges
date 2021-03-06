/*
The following is a solution to prompt 412. Fizz Buzz from leetcode.com
The prompt can be found here: https://leetcode.com/problems/fizz-buzz/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <string>
#include <vector>

class Solution {
public:
	std::vector<std::string> fizzBuzz(int n) {
		std::vector<std::string> statements;
		for (int i = 1; i <= n; i++) {
			if (!(i % 15))
				statements.push_back("FizzBuzz");
			else if (!(i % 5))
				statements.push_back("Buzz");
			else if (!(i % 3))
				statements.push_back("Fizz");
			else
				statements.push_back(std::to_string(i));
		}
		return statements;
	}
};

int main()
{
	Solution prompt;
	std::vector<std::string> output = prompt.fizzBuzz(100);
	for (std::string statement : output)
	{
		//https://stackoverflow.com/questions/10865957/c-printf-with-stdstring
		printf("%s\n", statement.c_str());	//not type safe ^^^
	}
    return 0;
}

