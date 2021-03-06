/*
The following is a solution to prompt 888. Fair Candy Swap from leetcode.com
I have included two solutions, my first O(n^2) solution and an O(n) solution.
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "pch.h"
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:
	int sum(std::vector<int>& values) {
		int size = values.size();
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += values[i];
		}
		return sum;
	}

	std::vector<int> fairCandySwap(std::vector<int>& A, std::vector<int>& B) {
		int difference = (sum(B) - sum(A)) / 2;
		std::unordered_set<int> s(B.begin(), B.end());
		for (int a : A) {
			if (s.count(a + difference))
				return std::vector<int>{a, a + difference};
		}
		return std::vector<int>(2, 0);
	}

	/*
	//O(n^2)
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
		int sum_a = sum(A);
		int mean = (sum_a + sum(B)) / 2;
		int diff_a = mean - sum_a;
		int size_a = A.size();
		int size_b = B.size();
		vector<int> swap_pair(2, 0);
		for(int i = 0; i < size_a; i++) {
			for(int j = 0; j < size_b; j++) {
				if(A[i] + diff_a == B[j]){
					swap_pair[0] = A[i];
					swap_pair[1] = B[j];
					return swap_pair;
				}
			}
		}
		return swap_pair;
	}
	*/
};

int main()
{
	Solution prompt;
	std::vector<int> A = { 1, 2, 5 };
	std::vector<int> B = { 2, 4 };
	prompt.fairCandySwap(A, B);
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
