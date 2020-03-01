#include <bits/stdc++.h>
using namespace std;
int main()
{
	// n chips on number line
	// i-th chip is placed at x-i
	// some chips can have equal coordinates
	// move 2 right or left for free
	// move 1 to the right or left for one coin
	// find the minimum total number of coins requires to move all n chips to the same coordinate
	int n;
	cin >> n;
	unsigned odd_count{ 0U };
	unsigned even_count{ 0U };
	int tmp;
	for(int i{ 0 }; i < n; ++i)
	{
		cin >> tmp;
		if(tmp & 0x1)	// odd
			++odd_count;
		else
			++even_count;
	}
	cout << min(even_count, odd_count) << endl;
}	
