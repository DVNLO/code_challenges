/*
The following is a solution to leetcode prompt 961 N repeated elements in a size
2N array. The prompt can be found here: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
Author: Dan Vyenielo
*/
#include "pch.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
	/*
	This solution leverages a property of a 2N array with one element value
	repeated N times. If there are N+1 unique elements then only one element
	can be repeated N times. Therefore, whenever we find a repeated element,
	it must be the element. Furthermore, the element must occur adjacent to 
	itself or it must occur in the 2nd element. Finally, it may also occur in 
	the first and terminal index positions. In this case we return the terminal
	element. 
	*/
	int repeatedNTimes_third(vector<int>& A) {
		const unsigned size = A.size();
		for (unsigned i = 2; i < size; ++i) {
			if (A[i] == A[i - 1] || A[i] == A[i - 2])
				return A[i];
		}
		return A[size - 1];
	}

	int repeatedNTimes_second(vector<int>& A) {
		unordered_set<int> S;
		for (const int a : A)
			if (S.count(a))
				return a;
			else
				S.insert(a);
	}

	int repeatedNTimes_first(vector<int>& A) {
		const int size = A.size();
		unordered_map<int, int> M;
		M.insert(make_pair(A[0], 1));
		auto max = M.find(A[0]);
		for (int i = 1; i < size; ++i) {
			if (M.count(A[i])) {
				++M[A[i]];
				if (M[A[i]] > max->second)
					max = M.find(A[i]);
			}
			else {
				M.insert(make_pair(A[i], 1));
			}
		}
		return max->first;
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
