#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; // cols;
	cin >> n;
	vector<int> a(n);
	for(int i{ 0 }; i < n; ++i)
		cin >> a[i];
	sort(begin(a), end(a));
	for(auto const & val : a)
		cout << val << ' ';
	cout << endl;
}
