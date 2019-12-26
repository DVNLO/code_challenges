#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int total_r{ 0 };
	int r{ 0 };
	int i{ 1 };
	while(i < n)
	{
		r = 0;
		while(i < n 
			&& s[i - 1] == s[i])
		{
			++i;
			++r;
		}
		if(!r)
			++i;
		else
			total_r += r;
	}
	cout << total_r << endl;
}
