#include <bits/stdc++.h>
using namespace std;

/* I was not able to come tot he simple solution below on my own.
 * The tutorial associated with this problem noted an important property
 * of all numbers that I should have remembered. All numbers can be formed
 * as a multiple of a prime. This is the central tennant of the sieve of
 * erathosthenes.
 */

bool process_query(long long const x, 
			long long const y)
{
	return x - y != 1;	// 1 is the only number without a prime divisor. 
				// all other differences are prime subtractable.
}
	
unordered_set<long long> sieve_of_erathosthenes(long long const max)
{
	vector<bool> is_prime(max - 2 + 1, true);
	long long sqrt_max{ static_cast<long long>(sqrt(max)) };
	for(long long i{ 2 }; i < sqrt_max; ++i)
	{
		if(is_prime[i])
		{
			for(long long j{ i * i }; j <= max; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
}
	
int main()
{
	int q;
	cin >> q;
	long long x, y;
	bool is_prime_subtractable;
	for(int i{ 0 }; i < q; ++i)
	{
		cin >> x >> y;
		is_prime_subtractable = process_query(x, y);
		if(is_prime_subtractable)
			puts("YES");
		else
			puts("NO");
	}
	cout << endl;
}
