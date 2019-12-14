#include <bits/stdc++.h>
using namespace std;

vector<int>::iterator partition(vector<int> & vals,
				vector<int>::iterator left,
				vector<int>::iterator right)
{
	int pivot{ *(left + ((right - left) / 2)) };
	--right;	// right is originally exclusive
	while(left < right)
	{
		while(*left < pivot)
			++left;
		while(*right > pivot)
			--right;
		swap(*left, *right);
	}
	return left;
}

// quick_sort vals within the half open range [lower_bound, upper_bound).
void quick_sort(vector<int> & vals, 
		vector<int>::iterator lower_bound,
		vector<int>::iterator upper_bound)
{
	if(!(lower_bound < upper_bound - 1))
		return;
	vector<int>::iterator separator{ partition(vals, 
							lower_bound, 
							upper_bound) };
	quick_sort(vals, lower_bound, separator);
	quick_sort(vals, separator, upper_bound);
}

int main()
{
	int n;
	cin >> n;
	if(n <= 0)
		return 0;
	vector<int> vals(n);
	for(int i{ 0 }; i < n; ++i)
		cin >> vals[i];
	quick_sort(vals, vals.begin(), vals.end());
	for(int i{ 0 }; i < n; ++i)
		cout << vals[i];
}
