#include <bits/stdc++.h>
using namespace std;

inline bool is_odd(int const val)
{
	return val % 2;
}

inline bool is_even(int const val)
{
	return !is_odd(val);
}

void print_grid(vector<vector<char>> const & grid)
{
	for(auto const & row : grid)
	{
		for(auto const & val : row)
		{
			cout << val;
		}
		cout << '\n';
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m, '.'));
	for(int i{ 0 }; i < n; ++i)
	{
		if(is_even(i))
		{
			for(int j{ 0 }; j < m; ++j)
				grid[i][j] = '#';
		}
		else
		{
			// odd
			// R : 1, 5, 9 ...
			// a_R = 1 + 4n
			// L : 3, 7, 11 ...
			// a_L = 3 + 4n
			if((i - 1) % 4 == 0)
			{
				// place # in right-most column
				grid[i][m - 1] = '#';
			}
			else
			{
				// place # in left-most column
				grid[i][0] = '#';
			}
		}
	}
	print_grid(grid);
	cout << endl;
}

