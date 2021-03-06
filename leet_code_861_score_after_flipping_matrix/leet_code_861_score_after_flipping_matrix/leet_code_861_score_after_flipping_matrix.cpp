/*
The following is a solution to prompt 861 Score After Flipping Matrix from
leetcode.com. The prompt can be found here: https://leetcode.com/problems/score-after-flipping-matrix/
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int col_set_bit_count(const vector<vector<int>>& mat, const int& col) {
		const int size = mat.size();
		int score = 0;
		for (int i = 0; i < size; ++i) {
			score += mat[i][col];
		}
		return score;
	}

	void toggle_row(vector<vector<int>>& mat, const int& row) {
		const int size = mat[row].size();
		for (int i = 0; i < size; ++i) {
			mat[row][i] = mat[row][i] ? 0 : 1;	//toggle
		}
	}

	void toggle_col(vector<vector<int>>& mat, const int& col) {
		const int size = mat.size();
		for (int i = 0; i < size; ++i) {
			mat[i][col] = mat[i][col] ? 0 : 1;	//toggle
		}
	}

	int compute_score(const vector<vector<int>> mat) {
		const int row_size = mat.size();
		int score = 0;
		for (int row = 0; row < row_size; ++row) {
			const int col_size = mat[row].size();
			int power = 1 << col_size - 1;
			for (int col = 0; col < col_size; ++col) {
				score += mat[row][col] * power;
				power >>= 1;
			}
		}
		return score;
	}

	int matrixScore(vector<vector<int>>& A) {
		if (A.empty())
			return 0;
		const int row_size = A.size();
		for (int row = 0; row < row_size; ++row) {	//set each not-set MSB
			if(!A[row][0])
				toggle_row(A, row);
		}
		const int col_size = A[0].size();
		if (col_size) {
			for (int col = 1; col < col_size; ++col) {
				const int half = row_size / 2 + 1;
				if (col_set_bit_count(A, col) < half) {
					toggle_col(A, col);	//only toggle if toggling would result in more than half of the bits set
				}
			}
		}
		return compute_score(A);
	}
};

int main()
{
	vector<vector<int>> A = { {0, 0, 1, 1},{1, 0, 1, 0 }, { 1, 1, 0, 0 } };
	Solution prompt;
	cout << prompt.matrixScore(A) << endl;
}