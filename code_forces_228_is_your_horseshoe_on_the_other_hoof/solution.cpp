#include <bits/stdc++.h>
using namespace std;
int main()
{
	// determine the minimum number of hs's to buy to weak different colors
	int duplicate_count{ 0 };
	unordered_set<int> s;
	int tmp;
	for(int i{ 0 }; i < 4; ++i)
	{
		cin >> tmp;
		if(s.count(tmp))
			++duplicate_count;
		else
			s.insert(tmp);
	}
	cout << duplicate_count << endl;
}
