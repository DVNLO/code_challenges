/*
The following is a solution to prompt 766 Toeplitz Matrix from leetcode.com.
The prompt can be found here: https://leetcode.com/problems/toeplitz-matrix/description/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "stdafx.h"
#include <iostream>
#include <vector>

class Solution {
public:
	bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
		int height = matrix.size();
		if (!height) return true;
		int width = matrix[0].size();
		if (!width) return true;
		for (int row = height - 1; row >= 0; row--) {
			if (!isToeplitzDiagonal(row, height - 1, 0, width - 1, matrix))
				return false;
		}
		for (int column = 1; column < width - 1; column++) {
			if (!isToeplitzDiagonal(0, height - 1, column, width - 1, matrix))
				return false;
		}
		return true;
	}

	bool isToeplitzDiagonal(const int& from_row, const int& to_row,
							const int& from_column, const int& to_column,
							const std::vector<std::vector<int>>& matrix)
	{
		int d_row = from_row;
		int d_column = from_column;
		while (d_row != to_row && d_column != to_column &&
			matrix[d_row][d_column] == matrix[d_row + 1][d_column + 1]) {
			d_row++;
			d_column++;
		}
		return d_row == to_row || d_column == to_column;
	}

	/*The following is code submitted and found on leetcode.com
	as a sample of the highest efficiency solution. I did not write
	this code, but it's an excellent example of how simple a 
	solution to this problem could be. It's impressivly intelligent. */
	bool peak_isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
		int m = matrix.size();
		if (!m) return true;
		int n = matrix[0].size();
		if (!n) return true;

		for (int i = 0; i < m - 1; ++i) {
			for (int j = 0; j < n - 1; ++j) {
				if (matrix[i][j] != matrix[i + 1][j + 1])	//genius
					return false;
			}
		}
		return true;
	}
};


int main()
{
	Solution prompt;
	std::vector<std::vector<int> > input = { {1,2,3,4},
											 {5,1,2,3},
											 {9,5,1,2 } };
	std::cout << prompt.isToeplitzMatrix(input) << std::endl;
    return 0;
}

