#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; // opponents in school
	//return the max number of consecutive days that he will beat all present opponents
	//if none are present araya still wins
	int d;	// number of days
	cin >> n >> d;
	vector<string> vs(d);
	for(int i{ 0 }; i < d; ++i)
	{
		cin >> vs[i]
	}
	vector<int> runs;
	for(auto const & day : vs)
	{
		int j{ 0 };
		for(; j < day.size(); ++j)
		{
			if(!day[j])
			{
				break;
			}
		}
		runs.emplace_back(j != day.size());
	}
	int max_run{ 0 };
	int cur_run{ 0 };
	for(int i{ 0 }; i < runs.size(); ++i)
	{
		int j{ i + 1 };
		while(j < runs.size() && )
		for(int j{ i + 1 }; j < runs.size(); ++j)
		{
			
