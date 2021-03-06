/*
The following is an attempt to implement a linear solution to this problem 
from leetcode. This did not solve the problem as written, but I maintain 
suspicious that an O(n) solution exists using a greedy algorithm.
*/

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int largestPerimeter(vector<int>& A) {
		int a = 0;
		int b = 0;
		int c = 0;
		unsigned const size = A.size();
		for (unsigned i = 0; i < size; ++i)
		{
			if (A[i] > a && A[i] < b + c && b < A[i] + c && c < b + A[i])
			{
				std::cout << "swap" << a << ' ' << A[i] << '\n';
				swap(a, A[i]);
			}
			if (A[i] > b && A[i] < a + c && a < A[i] + c && c < a + A[i])
			{
				std::cout << "swap" << b << ' ' << A[i] << '\n';
				swap(b, A[i]);
			}
			if (A[i] > c && A[i] < a + b && a < A[i] + b && b < a + A[i])
			{
				std::cout << "swap" << c << ' ' << A[i] << '\n';
				swap(c, A[i]);
			}
		}
		return (a >= (b + c) || b >= (a + c) || c >= (a + b)) ? 0 : a + b + c;
	}
};

int main()
{
	Solution prompt;
	vector<int> A = { 3, 6, 2, 3 };
	cout << prompt.largestPerimeter(A) << endl;
}