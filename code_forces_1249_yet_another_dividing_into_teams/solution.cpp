#include <bits/stdc++.h>
using namespace std;


/*
// The followig solution is incorrect because it
// depends on the sequence elements are added
// to the vector of sets structure. After reading
// the tutorial it is clear that the minimum must
// always be 1 or 2 teams because any number 
// can only every overlap with it's directly adjacent
// number. 
int process_query(vector<int> & a, int n)
{
	int team_count{ 1 };
	vector<unordered_set<int>> vs(team_count);
	for(int i{ 0 }; i < n; ++i)
	{
		bool placed{ false };
		int j{ 0 };
		while(j < team_count 
			&& !placed)
		{
			if(!(vs[j].count(a[i] - 1) 
				|| vs[j].count(a[i] + 1)))
			{
				vs[j].insert(a[i]);
				placed = true;
			}
			++j;
		}
		if(!placed)
		{
			unordered_set<int> s;
			s.insert(a[i]);
			vs.emplace_back(s);
			++team_count;
		}
	}
	return team_count;
}
*/


// The following solution is correct because we can form teams
// by simply seperating any adjacent numbers. For example
// 0 1 2 3 7 8 9 can be split to the two teams:
// 0 2 7 9
// 1 3 8 
int process_query(vector<int> & a, int n)
{
	bool split_teams{ false };
	for(int i{ 0 }; i < n && !split_teams; ++i)
	{
		for(int j{ 0 }; j < n && !split_teams; ++j)
		{
			if(abs(a[i] - a[j]) == 1)
				split_teams = true;
		}
	}
	return split_teams ? 2 : 1;
}

int main()
{
		// n students
		// ith student has programming skill ai
		// all students have distinct programming skills
		// divide into teams such that
		// 	1. no two students i, j such that |ai - aj| = 1;
		// 	2. number of teams is min possible. 
		// answer q indepentent queries
	int q;
	cin >> q;
	int n;
	vector<int> res(q);
	for(int k{ 0 }; k < q; ++k)
	{
		cin >> n;
		vector<int> a(n);
		for(int i{ 0 }; i < n; ++i)
			cin >> a[i];
		res[k] = process_query(a, n);
	}
	for(int k{ 0 }; k < q; ++k)
		cout << res[k] << '\n';
	cout << endl;
}
