/*
The following is my solution to prompt 942 DI String Match from leetcode.com.
The original prompt and driver can be found here: https://leetcode.com/problems/di-string-match/
Author: Dan Vyenielo
*/
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> diStringMatch(string S) {
		const unsigned size = S.length();
		int min = 0;
		int max = size;
		vector<int> A(size + 1);
		for (unsigned i = 0; i < size; ++i) {
			if (S[i] == 'I') {
				A[i] = min;
				++min;
			}
			else {
				A[i] = max;
				--max;
			}
		}
		A[size] = max;
		return A;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
