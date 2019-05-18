#include <cmath>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0)
	{
		vector<vector<vector<int>>> ordered_points(R + C - 2);
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				int dist = abs(r - r0) + abs(c - c0);
				ordered_points[dist].push_back({ r, c });
			}
		}
		vector<vector<int>> points; 
		for(int dist = 0; ;)
		return ordered_points;
	}
};