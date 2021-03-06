/*
The following is a solution to prompt 905. Sort Array By Parity
from leetcode.com. I have included three solutions, representing 
my progression through correct submissions.
*/
#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
	std::vector<int> sortArrayByParity_0(std::vector<int>& A) {
		int i = 0;
		int j = A.size() - 1;
		while (i < j) {
			while (!(A[i] % 2)) //A[i] is even;
				i++;
			while (A[j] % 2) //A[j] is odd
				j--;
			if (i < j) {
				std::swap(A[i], A[j]);
			}
		}
		return A;
	}

	std::vector<int> sortArrayByParity_1(std::vector<int>& A) {
		int i = 0;
		int j = A.size() - 1;
		while (i < j) {
			bool left = A[i] % 2;
			bool right = A[j] % 2;
			if (!left)    // is even
				i++;
			if (right)   //is odd
				j--;
			if (left && !right)
				std::swap(A[i], A[j]);
		}
		return A;
	}

	std::vector<int> sortArrayByParity_2(std::vector<int>& A) {
		int i = 0;
		int j = A.size() - 1;
		while (i < j) {
			if (A[i] % 2 && !(A[j] % 2)) {
				std::swap(A[i], A[j]);
				i++;
				j--;
			}
			else {
				if (!(A[i] % 2)) //A[i] is even
					i++;
				if (A[j] % 2)    //A[j] is odd
					j--;
			}
		}
		return A;
	}
};

int main()
{
	Solution prompt;
	std::vector<int> A = { 1,2,3,4,5 };
	prompt.sortArrayByParity_0(A);
	prompt.sortArrayByParity_1(A);
	prompt.sortArrayByParity_2(A);
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
