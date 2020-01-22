#include <bits/stdc++.h>
using namespace std;


// I really like this solution. Beautiful.
// Memoization solution.
int fib(int const n, vector<int> & fibs)
{
	if(n < 0)
		return -1;
	else if(n < fibs.size())
		return fibs[n];
	else // n >= fibs.size()
	{
		int j{ static_cast<int>(fibs.size()) };
		if(!j)
		{
			fibs.emplace_back(0);
			++j;
		}
		if(j == 1)
		{
			fibs.emplace_back(1);
			++j;
		}
		while(j <= n)
		{
			fibs.emplace_back(fibs[j - 2] + fibs[j - 1]);
			++j;
		}
		return fibs[n];
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> fibs;
	for(int i{ n }; i >= 0 ; --i)
	{
		fib(i, fibs);
		cout << fib(n - i, fibs) << ' ';
	}
	cout << endl;
}
