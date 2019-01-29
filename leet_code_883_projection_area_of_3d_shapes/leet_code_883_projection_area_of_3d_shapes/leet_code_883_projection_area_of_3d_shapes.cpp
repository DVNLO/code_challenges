/*
The following is a solution to leetcode prompt 883 Projection Area of 3D 
shapes. No driver is provided. The prompt can be found here:
https://leetcode.com/problems/projection-area-of-3d-shapes/
Author: Dan Vyenielo
*/
#include "pch.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int projectionArea(vector<vector<int>>& grid)
	{
		const unsigned xs = grid.size();    //xs is row size
		const unsigned ys = grid[0].size();
		int xy = 0; //total projected xy area
		int xz = 0; //total projected xz area
		int yz = 0; //total projected yz area
		vector<int> maxs_xz(xs, 0);
		vector<int> maxs_yz(ys, 0);
		for (unsigned x = 0; x < xs; ++x)
		{
			for (unsigned y = 0; y < ys; ++y)
			{
				int val = grid[x][y];
				if (val > 0)
					++xy;
				maxs_xz[x] = max(val, maxs_xz[x]);
				maxs_yz[y] = max(val, maxs_yz[y]);
			}
		}
		for (const int max_xz : maxs_xz)
			xz += max_xz;
		for (const int max_yz : maxs_yz)
			yz += max_yz;
		return xy + xz + yz;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
