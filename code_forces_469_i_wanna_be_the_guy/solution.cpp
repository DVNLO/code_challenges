#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; // levels
	cin >> n;
	int p; // little x can pass only p levels
	cin >> p;
	vector<bool> level_passed(n, false);
	int level;
	for(int i{ 0 }; i < p; ++i)
	{
		cin >> level;
		--level;
		if(!level_passed[level])
			level_passed[level] = true;
	}
	int q; // little y can pass only q levels
	cin >> q;
	for(int i{ 0 }; i < q; ++i)
	{
		cin >> level;
		--level;
		if(!level_passed[level])
			level_passed[level] = true;
	}
	int i{ 0 };
	while(i < n 
		&& level_passed[i])
		++i;
	if(i == n)
		puts("I become the guy.");
	else
		puts("Oh, my keyboard!");
}
