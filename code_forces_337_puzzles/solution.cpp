#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m; // n students, m puzzles in the shop
	cin >> n >> m;
	vector<int> f(m);
	for(int i{ 0 }; i < m; ++i)
		cin >> f[i];
	// choose n puzzles such that A - B is the minimum possible
	sort(begin(f), end(f));
	vector<int>::iterator B{ begin(f) };
	vector<int>::iterator A{ B };
	advance(A, n - 1);
	vector<int>::const_iterator const END{ end(f) };
	int min_diff{ *A - *B };
	while(A < END)
	{
		int diff{ *A - *B };
		if(diff < min_diff)
			min_diff = diff;
		++A;
		++B;
	}
	cout << min_diff << endl;
}
