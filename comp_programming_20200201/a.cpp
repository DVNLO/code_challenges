#include <bits/stdc++.h>
using namespace std;

int handle_query(long long n)
{
	int num_moves = 0;
	while(n != 1)
	{
		if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0)
			return -1;
		while((n % 2) == 0)
		{
			n /= 2;
			++num_moves;
		}
		while((n % 3) == 0)
		{
			n /= 3;
			n *= 2;
			++num_moves;
		}
		while((n % 5) == 0)
		{
			n /= 5;
			n *= 4;
			++num_moves;
		}
	}
	return num_moves;
}

int main()
{
	int q;
	long long n;
	// the following operations are valid
	// replace n with n/2 iff n is div by 2
	// replace n with 2n/3 iff n is div 3
	// replace n with 4n/5 iff n is div 5
	// find min number of moves required to obtain 1 from n or say that is is impossible. 
	cin >> q;
	vector<int> v(q);
	for(int i { 0 }; i < q; ++i)
	{
		cin >> n;
		v[i] = handle_query(n);
	}
	for(int i { 0 }; i < q; ++i)
		cout << v[i] << '\n';
}
