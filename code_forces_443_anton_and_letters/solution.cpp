#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin, s);
	unordered_set<char> u;
	for(auto const c : s)
	{
		if(isalpha(c) && !u.count(c))
		{
			u.insert(c);
		}
	}
	cout << u.size() << endl;
}
