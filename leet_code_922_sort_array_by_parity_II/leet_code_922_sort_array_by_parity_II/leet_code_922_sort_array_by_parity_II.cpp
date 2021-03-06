/*
The following is a solution to prompt 922 Sort Array By Parity II from
from leetcode.com (https://leetcode.com/problems/sort-array-by-parity-ii/)
I have included two solutions. The first is my initial implementation. 
The second is an implementation modeled after the solution provided by leetcode.
I have not included a driver. 
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "pch.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> sortArrayByParityII_one(vector<int>& A) {
		stack<int> eo;  //store even index with odd value
		stack<int> oe;  //store odd index with even value
		const int size = B.size();
		for (int i = 0, mod; i < size; i++) {
			mod = i % 2;
			if (mod != B[i] % 2) {
				if (mod)
					oe.push(i);
				else
					eo.push(i);
			}
		}
		while (!eo.empty() && !oe.empty()) {
			swap(B[eo.top()], B[oe.top()]);
			eo.pop();
			oe.pop();
		}
		return A;
	}

	vector<int> sortArrayByParityII_second(vector<int>& A) {
		int evens = 0;
		int odds = 1;
		const int size = A.size();
		while (evens < size && odds < size) {
			if (A[evens] % 2) {
				while (odds < size && A[odds] % 2)
					odds += 2;
				swap(A[evens], A[odds]);
			}
			evens += 2;
		}
		return A;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}