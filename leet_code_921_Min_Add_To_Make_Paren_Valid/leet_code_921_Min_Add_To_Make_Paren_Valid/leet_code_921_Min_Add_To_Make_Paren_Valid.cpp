/*
The following are solutions to prompt 921 Minimum Add To Make Parenthesis 
Valid from leetcode.com 
(https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/). I have 
implemented two solutions. minAddToMakeValid_algo(...) utilizes a "balancing"
counter to compute the number of parenthesis to add. Anytime a negative balance
is computed, there is no possibility of resolving the imbalance later in the 
string, so the unbalanced parenthesis is added to the count, and iteration
continues. minAddToMakeValid_stack(...) utilizes a stack to keep track of
parenthesis coupling. Anytime the stack's top is an open parenthesis and the 
current character within S is closing we pop the open parenthesis off the 
stack. Note: the stack can be empty during iteration. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "pch.h"
#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
	int minAddToMakeValid_algo(std::string S) {
		int i = 0, count = 0, balance = 0;
		const int size = S.size();
		while (i < size) {
			if (S[i] == '(') {
				balance++;
			}
			else if (S[i] == ')')
				balance--;
			if (balance < 0) {
				count += abs(balance);
				balance = 0;
			}
			i++;
		}
		return count + balance;
	}

	int minAddToMakeValid_stack(std::string S) {
		if (S.empty())
			return 0;
		int i = 0;
		const int size = S.size();
		std::stack<char> parens;
		parens.push(S[i]);
		i++;
		char top;
		while (i < size) {
			if (!parens.empty() && (parens.top() == '(' && S[i] == ')')) {
				parens.pop();
			}
			else {
				parens.push(S[i]);
			}
			i++;
		}
		return parens.size();
	}
};

int main()
{
	Solution prompt;
	std::string my_string = "()(((())))()()()))))))(((()()()))))))";
	std::cout << "my_string == " << my_string << std::endl;
	std::cout << "prompt.minAddToMakeValid_algo(my_string) == ";
	std::cout << prompt.minAddToMakeValid_algo(my_string) << std::endl;
	std::cout << "prompt.minAddToMakeValid_stack(my_string) == ";
	std::cout << prompt.minAddToMakeValid_stack(my_string) << std::endl;
}