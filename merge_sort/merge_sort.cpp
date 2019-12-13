#include <bits/stdc++.h>
using namespace std;


void merge(vector<int> & left, 
		vector<int> & right,
		vector<int> & target)
{
	vector<int>::iterator l{ left.begin() };
	vector<int>::const_iterator const LEFT_END{ left.cend() };
	vector<int>::iterator r{ right.begin() };
	vector<int>::const_iterator const RIGHT_END{ right.cend() };
	vector<int>::iterator t{ target.begin() };
	vector<int>::const_iterator const TARGET_END{ target.cend() };
	while(t < TARGET_END)
	{
		while(t < TARGET_END 
			&& (r >= RIGHT_END || (l < LEFT_END && *l < *r)))
		{
			*t = *l;
			++t;
			++l;
		}
		while(t < TARGET_END 
			&& (l >= LEFT_END || (r < RIGHT_END && *r < *l)))
		{
			*t = *r;
			++t;
			++r;
		}
	}
}

void merge_sort(vector<int> & source, 
		vector<int>::iterator const & lower_bound, 
		vector<int>::iterator const & upper_bound)
{
	if(source.empty() || upper_bound - lower_bound <= 1)
		return;
	vector<int>::iterator midpoint{ lower_bound + ((upper_bound - lower_bound) / 2) };
	vector<int> left{ lower_bound, midpoint };
	merge_sort(left, left.begin(), left.end());
	vector<int> right{ midpoint, upper_bound };
	merge_sort(right, right.begin(), right.end());
	merge(left, right, source);
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i{ 0 }; i < n; ++i)
		cin >> v[i];
	merge_sort(v, v.begin(), v.end());
	for(int i{ 0 }; i < n; ++i)
		cout << v[i];
}
