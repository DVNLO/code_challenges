// The following solution is incorrect because the order of the
// elements in the subsequence matters. We are only allowed to remove elements.
// we cannot sort the array. 

#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int tmp_val;
	unordered_map<int, unsigned> freq{ { 4, 0U}, {8, 0U}, {15, 0U}, {16, 0U}, {23, 0U}, {42, 0U} };
	unsigned min_freq{ numeric_limits<unsigned>::max() };
	for(int i{ 0 }; i < n; ++i)
	{
		cin >> tmp_val;
		if(freq.count(tmp_val))
			++freq[tmp_val];
		else
			freq[tmp_val] = 1U;
	}
	for(auto const f : freq)
	{
		if(f.first == 4 || f.first == 8
			|| f.first == 15 || f.first == 16
			|| f.first == 23 || f.first == 42)
			min_freq = min(min_freq, f.second);
	}
	//unsigned removal_count{ 0 };
	//for(auto const f : freq)
	//{
	//	if(f.first != 4 && f.first != 8
	//		&& f.first != 15 && f.first != 16
	//		&& f.first != 23 && f.first != 42)
	//		removal_count += f.second;
	//	else
	//		removal_count += f.second - min_freq;
	//}
	cout << n - 6 * min_freq << endl;
}		
