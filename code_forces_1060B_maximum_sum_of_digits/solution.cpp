#include <bits/stdc++.h>
using namespace std;

long long s(long long x)
//returns the sum of the digits of x in base 10
{
	long long ret{ 0 };
	while(x)
	{
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int main()
// returns the maximum sum of the digits of two numbers a, b
// such that a >= 0 and b <= n and a + b = n. Computes the 
// maximum sum by maximizing the number of 9's in a and
// computing the sum of the digits in b = m - n where m is
// the maximum number composed of only 9's (9, 99, 999, etc.)
// This is a great problem. It emphasises a greedy method,
// and it's relatively straightforward to grasp the problem 
// statement quickly.
{
	long long n;
	cin >> n;
	long long a{ n };
	long long d{ 0 }; // digit count;
	while(a)
	{
		a /= 10;
		++d;
	}
	long long m{ 0 };
	for(long long i{ 0 }; i < d; ++i)
		m = 10 * m + 9;
	if(m > n)
		m = (m - 9) / 10;
	cout << s(m) + s(n - m) << endl;
}
