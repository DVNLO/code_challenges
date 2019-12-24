#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<bool> line(m, false);
	int left;
	int right;
	int unmarked{ m };
	for(int i{ 0 }; i < n; ++i)
	{
		cin >> left >> right;
		for(int j{ left - 1 }; j < right; ++j)
		{
			if(!line[j])
			{
				line[j] = true;
				--unmarked;
			}
		}
	}
	cout << unmarked;
	if(unmarked)
	{
		cout << '\n';
		for(int i{ 0 }; i < m; ++i)
		{
			if(!line[i])
				cout << i + 1 << ' ';
		}
	}
	cout << endl;
}
