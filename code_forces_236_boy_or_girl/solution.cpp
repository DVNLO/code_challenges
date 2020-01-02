#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	set<char> symbol_count;
	for(auto const c : s)
	{
		if(!symbol_count.count(c))
			symbol_count.insert(c);
	}
	if(symbol_count.size() & 0x1)	// is odd -> male
		puts("IGNORE HIM!");
	else
		puts("CHAT WITH HER!");
}
