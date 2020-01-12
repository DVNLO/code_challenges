#include <bits/stdc++.h>
using namespace std;
int main()
{
	// n coins of arbitrary values a1 ... an;
	// split money equally.
	// pick the set of coins such that your set is strinctly largen than the sim of values of the remainin coins
	// take the minimum number of coins whose sum of values is strictly more than the sum of value of the remainin coins. 
	// determin what minimum number of coins you need to take to divide them in the described manner. 
	int n;
	cin >> n;
	long long his_sum{ 0 };
	vector<int> a(n);
	for(int i{ 0 }; i < n; ++i)
	{
		cin >> a[i];
		his_sum += a[i];
	}
	sort(begin(a), end(a), greater<int>());
	int i{ 0 };
	long long my_sum{ 0 };
	while(i < n 
		&& my_sum <= his_sum)
	{
		my_sum += a[i];
		his_sum -= a[i];
		++i;
	}
	cout << i << endl;
}
