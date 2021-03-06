/*
The following is a collection of solutions to prompt 896. Monotonic Array
from leetcode.com. I included a couple solutions labeled in the order 
with which I arrived at them. Note that the second solution reduced
memory acces operations be eliminating the additional integer variables
and thus reducing the total number of memory access event. As such, the 
second function operates much faster. The prompt can be found here:
https://leetcode.com/problems/monotonic-array/description/
Author: Dan Vyeniel (dvyenielo@gmail.com)
*/

#include "pch.h"
#include <iostream>
#include <vector>

class Solution {
public:
	bool isMonotonic_2(std::vector<int>& A) {
		int i = 1;
		int size = A.size();
		while (i < size && A[i - 1] <= A[i]) {  //increasing
			i++;
		}
		int j = 1;
		while (j < size && A[j - 1] >= A[j]) {  //decreasing
			j++;
		}
		return i == size || j == size;
	}

	bool isMonotonic_1(std::vector<int>& A) {
		int i = 0;
		int j = 1;
		int size = A.size();
		while (j < size && A[i] <= A[j]) {  //increasing
			i++;
			j++;
		}
		int k = 0;
		int l = 1;
		while (l < size && A[k] >= A[l]) {  //decreasing
			k++;
			l++;
		}
		return j == size || l == size;
	}
};

int main()
{
	Solution prompt;
	std::vector<int> A = { 1,2,3,4,5,10 };
	prompt.isMonotonic_1(A);
	prompt.isMonotonic_2(A);
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
