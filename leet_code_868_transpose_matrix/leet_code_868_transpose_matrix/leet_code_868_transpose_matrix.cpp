/*
The following is a solution to prompt 868. Transpose Matrix from 
leetcode.com. This code requires the leetcode.com environment to run,
or initialization of a matrix A to execute, as no driving function call
is provided. 
The prompt can be found : https://leetcode.com/problems/transpose-matrix/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "stdafx.h"
#include <vector>

class Solution {
public:
	std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& A) {
		int ARowCount = A.size();
		int AColumnCount = A[0].size();
		std::vector<std::vector<int>> B(AColumnCount, std::vector<int>(ARowCount));
		for (int row = 0; row < ARowCount; row++) {
			for (int column = 0; column < AColumnCount; column++) {
				B[column][row] = A[row][column];
			}
		}
		return B;
	}
};

int main()
{
	Solution prompt;
    return 0;
}

