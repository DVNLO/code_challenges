#include <bits/stdc++.h>
using namespace std;
int main()
{
	// find the max length of an increasing sub array within the given array
	// consecutive elements of arr
	// increasing if each element is STRICTLY GREATER
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i{ 0 }; i < n; ++i)
		cin >> v[i];
	unsigned max_len_inc_sub_arr{ 1U };
	unsigned len_inc_sub_arr{ 1U };
	for(int i{ 1 }; i < n; ++i)
	{
		len_inc_sub_arr = 1;
		while(i < n 
			&& v[i] > v[i - 1])
		{
			++len_inc_sub_arr;
			++i;
		}
		max_len_inc_sub_arr = max(max_len_inc_sub_arr, len_inc_sub_arr);
	}
	cout << max_len_inc_sub_arr << endl;
}
