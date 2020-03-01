#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long A{ 0 };
	long long max_A{ A };
	int a, b;
	for(int i{ 0 }; i < n; ++i)
	{
		cin >> a;
		A -= a;
		cin >> b;
		A += b;
		if(A > max_A)
			max_A = A;
	}
	cout << max_A;
}
