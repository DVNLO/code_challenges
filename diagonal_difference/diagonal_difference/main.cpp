/*This program computes the absolute difference of diagonals for a square,
non-negative, two dimensional vector (matrix). Matrix values are randomly generated.
Author: Dan Vyenielo
Date: 9/1/2017*/

#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <string>
#include <cmath>
using namespace std;

bool is_dimension_valid(const int dimension);
void prompt_user(int &dimension);
void gen_rand_NxN_matrix(vector<vector<int> > &matrix, const int dimension);
void print_NxN_matrix(const vector<vector<int> > &matrix);
int sum_left_diag_NxN_matrix(vector<vector<int> > &matrix);
int sum_right_diag_NxN_matrix(vector<vector<int> > &matrix);

int main() {
	int dimension = -1;
	vector<vector<int> > matrix;
	srand(static_cast<int>(time(0)));

	while (!(is_dimension_valid(dimension))) {
		prompt_user(dimension);
	}
	gen_rand_NxN_matrix(matrix, dimension);
	print_NxN_matrix(matrix);
	int sum_left_diag = sum_left_diag_NxN_matrix(matrix);
	cout << "The left diagonal sum is: " << sum_left_diag << endl;
	int sum_right_diag = sum_right_diag_NxN_matrix(matrix);
	cout << "The right diagonal sum is: " << sum_right_diag << endl;
	int	abs_difference = abs(sum_left_diag - sum_right_diag);
	cout << "The absolute difference of the diagonals is: " << abs_difference << endl;
	return 0;
}

bool is_dimension_valid(const int dimension) {
	return (dimension > 0);
}

void prompt_user(int &dimension) {
	string header_footer = "-----------------------------------------------------------";
	cout << header_footer << endl;
	cout << "Enter a dimension value to generate a random square matrix: ";
	cin >> dimension;
	if (!(is_dimension_valid(dimension)))
		cout << "Invalid entry. Please enter a positive, non-zero, dimension." << endl;
	cout << header_footer << endl;
}

void gen_rand_NxN_matrix(vector<vector<int> > &matrix, const int dimension) {
	matrix.begin();
	if (matrix.size() < dimension)
		matrix.resize(dimension);
	for (int i = 0; i < dimension; i++) {
		for (int j = 0; j < dimension; j++) {
			matrix[i].push_back(rand() % 10);	//assign rand() between 0-9
		}
	}
}

void print_NxN_matrix(const vector<vector<int> > &matrix) {
	int N = matrix.size();	//number of elements in a square matrix
	cout << "Print square matrix." << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << matrix[i][j] << ' ';
			if (j == (N - 1))	//return at end of row
				cout << endl;
		}
	}
}

int sum_left_diag_NxN_matrix(vector<vector<int> > &matrix) {
	int N = matrix.size();
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += matrix[i][i];
	}
	return sum;
}

int sum_right_diag_NxN_matrix(vector<vector<int> > &matrix) {
	int N = matrix.size();
	int sum = 0;
	for (int i = (N - 1); i >= 0; i--) {
		sum += matrix[(N - 1) - i][i]; //begin at the top right element
	}
	return sum;
}