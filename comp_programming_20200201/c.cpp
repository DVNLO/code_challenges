// The following solution is incorrect because the order of the
// elements in the subsequence matters. We are only allowed to remove elements.
// we cannot sort the array. 

#include <bits/stdc++.h>
using namespace std;

bool factor_subsequence(vector<int> & v, int & idx_first_4)
{
	static vector<int> const valid_subsequence{ 4, 8, 15, 16, 23, 42 };	
	int i{ 0 };
	int j{ idx_first_4 };
	while(i < 6 && j < v.size())
	{
		while(j < v.size() && v[j] != valid_subsequence[i])
			++j;
		if(j >= v.size())
			break;
		else
		{
			if(i == 0)
				idx_first_4 = j;
			v[j] = 0;
			++j;
			++i;
		}
	}
	return i == 6;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i{ 0 }; i < n; ++i)
	{
		cin >> v[i];
	}
	int possible_valid_subsequences{ n / 6 };
	int valid_subsequence_count{ 0 };
	int idx_first_4{ 0 };
	while(factor_subsequence(v, idx_first_4))
	{
		++valid_subsequence_count;
		++idx_first_4;
	}
	cout << n - 6 * valid_subsequence_count << endl;
}		
