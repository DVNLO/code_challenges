#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> const & lhs, 
		pair<int, int> const & rhs)
{
	// the lhs should come before rhs if
	//cout << lhs.first << " <= " << rhs.first << " && " << lhs.second << " > " <<  rhs.second << '\n';
	return lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second);
}

int main()
{
	int n; // dragons
	int s; // kirito's initial strength
	cin >> s >> n;
	vector<pair<int, int>> v(n);
	for(int i{ 0 }; i < n; ++i)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
//	for(int i{ 0 }; i < n; ++i)
//		cout << v[i].first << ' ' << v[i].second << '\n';
	// if kirito defeates the i-th dragon he gets bonus strength yi
	int i{ 0 };
	while(i < n 
		&& s > v[i].first)
	{
		s += v[i].second;
		++i;
	}
	if(i == n)
		puts("YES");
	else
		puts("NO");
}

