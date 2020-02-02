#include <bits/stdc++.h>
using namespace std;

int handle(vector<int> v, int const n)
{
	// can choose two element of arr and replace them with the element equal to their sum
	// find the max possible num elms div 3
}

int main()
{
	int t; 	// num queries
	cin >> t;
	int n;
	vector<int> ret(t);
	for(int i{ 0 }; i < t; ++i)
	{
		cin >> n;
		vector<int> v(n);
		for(int j{ 0 }; j < n; ++j)
			cin >> v[j];
		ret[i] = handle(v, n);
	}
	for(int i{ 0 }; i < t; ++i)
		cout << ret[i] << '\n';
	cout << endl;
}


