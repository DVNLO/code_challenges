#include <bits/stdc++.h>
using namespace std;
int main()
{
	int row_count, col_count;
	cin >> row_count >> col_count;
	vector<vector<char>> m(row_count, 
				vector<char>(col_count, '.'));
	char c;
	for(int i{ 0 }; i < row_count; ++i)
	{
		for(int j{ 0 }; j < col_count; ++j)
		{
			cin >> c;
			if(c == 'S')
				m[i][j] = c;
		}
	}
	int eatable_row_count{ 0 };
	for(int i{ 0 }; i < row_count; ++i) // scan by row
	{
		int j{ 0 };
		while(j < col_count 
			&& m[i][j] != 'S')
			++j;
		if(j == col_count)
			++eatable_row_count;
	}
	int eatable_col_count{ 0 };
	for(int i{ 0 }; i < col_count; ++i) // scan by col
	{
		int j{ 0 };
		while(j < row_count
			&& m[j][i] != 'S')
			++j;
		if(j == row_count)
			++eatable_col_count;
	}
	int eatable_cell_count{ eatable_row_count * col_count
					+ eatable_col_count * row_count 
					- eatable_row_count * eatable_col_count };
	cout << eatable_cell_count << endl;
}
