#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<string> vs;
	string s;
	for(int i{ 0 }; i < n; ++i)
	{
		cin >> s;
		auto len{ s.size() };
		if(len > 10)
			vs.emplace_back(s[0] + to_string(len - 2) + s[len - 1]);
		else
			vs.emplace_back(s);
	}
	for(int i{ 0 }; i < n; ++i)
	{
		cout << vs[i] << '\n';
	}
	cout << endl;
}

