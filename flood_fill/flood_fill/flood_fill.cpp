/*
The following is a "flood fill" algorithm in a binary matrix.
Author: Dan Vyenielo (dvyenielo@gmail.com)
*/
#include "pch.h"
#include <iostream>
#include <vector>

void print(bool*const*const& map, const int& row_limit, const int& col_limit) {
	for (int row = 0; row < row_limit; row++) {
		for (int col = 0; col < col_limit; col++) {
			std::cout << map[row][col] ? 1 : 0;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/*
0010000010
0010000010
1111111111
0010000010
0010000010
0010000010
0010000010
0010000010
1111111111
0010000010
*/
void flood_fill(bool *const *const& map, const int x, const int x_limit, const int y, const int y_limit) {
	if (x < 0 || x > x_limit || y < 0 || y > y_limit || map[x][y])
		return;
	map[x][y] = true;
	flood_fill(map, x, x_limit, y - 1, y_limit);	//north
	flood_fill(map, x + 1, x_limit, y, y_limit);	//east
	flood_fill(map, x, x_limit, y + 1, y_limit);	//south
	flood_fill(map, x - 1, x_limit, y, y_limit);	//west
}


int main()
{
	const int size = 20;
	const int left = 2;
	const int right = 18;
	const int top = 2;
	const int bottom = 18;
	bool** map = new bool*[size];
	for (int i = 0; i < size; i++) {
		map[i] = new bool[size];
	}
	std::cout << "Before::" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if (row == top || row == bottom || col == left || col == right) {
				map[row][col] = true;
			}
			else
				map[row][col] = false;
			std::cout << map[row][col] ? 1 : 0;
		}
		std::cout << std::endl;
	}
	flood_fill(map, 5, size, 5, size);
	std::cout << "---------------------------------" << std::endl;
	std::cout << "After::" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	print(map, size, size);
}