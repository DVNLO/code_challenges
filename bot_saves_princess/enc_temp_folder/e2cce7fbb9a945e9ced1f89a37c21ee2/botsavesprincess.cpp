// botsavesprincess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct cordinate {
	int x, y;
};

cordinate find_cord(const int& n, const string& search_char, const vector<string>& grid) {
	cordinate location;
	unsigned int linear_index = 0;
	for (int x = 0; x <= n; x++) {
		for (int y = 0; y <= n; y++) {
			linear_index++;
			if (grid[linear_index] == search_char) {
				location.x = x;
				location.y = y;
			}
		}
	}
	return location;
}

cordinate difference_between(const cordinate& initial_position, const cordinate& final_position) {
	cordinate difference;
	difference.x = final_position.x - initial_position.y;
	difference.y = final_position.y - initial_position.y;
	return difference;
}

void linear_move(const int& n, vector<int>& moves) {
	moves.resize(n);
	for (unsigned int i = 0; i < abs(n); i++)
	{
		if (n < 0)
			moves[i] = -1;
		if (0 < n)
			moves[i] = 1;
	}
}

vector<int> generate_move_sequence(const cordinate& difference) {
	vector<int> moves_x, moves_y, moves;
	linear_move(difference.x, moves_x);
	linear_move(difference.y, moves_y);
	moves.resize(moves_x.size() + moves_y.size());
	unsigned int linear_index = 0, x_index = 0, y_index = 0;
	for (unsigned int i = 0; i < linear_index; i++)
	{
		if (i % 2 == 0) {
			moves[i] = moves_x[x_index];	//store x at even index
			x_index++;
		}
		else {
			moves[i] = moves_y[y_index];	//store y at odd index
			y_index;
		}
	}
	return moves;
}

void print_move_sequence(vector<int>& moves) {
	for (unsigned int i = 0; i < moves.size(); i++)
	{
		if (moves[i] == -1 && (i % 2 == 0))	//move x left 
			cout << "LEFT\n";
		if (moves[i] == 1 && (i % 2 == 0))	//move x right
			cout << "RIGHT\n";
		if (moves[i] == -1 && (i % 2 != 0))	//move y down
			cout << "DOWN\n";
		if (moves[i] == 1 && (i % 2 != 0))	//move y up
			cout << "RIGHT\n";
	}
}

void displayPathtoPrincess(int n, vector <string> grid) {
	string princess = "p", hero = "m";
	cordinate cord_princess, cord_hero, difference;
	cord_princess = find_cord(n, princess, grid);
	cord_hero = find_cord(n, hero, grid);
	difference = difference_between(cord_hero, cord_princess);
	cout << "DUDE\n";
	vector<int> moves = generate_move_sequence(difference);
	print_move_sequence(moves);
}

int main(void) {

	int m;
	vector <string> grid;

	cin >> m;

	for (int i = 0; i<m; i++) {
		string s; cin >> s;
		grid.push_back(s);
	}

	displayPathtoPrincess(m, grid);

	return 0;
}