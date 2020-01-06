#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long k, n, w;
	cin >> k >> n >> w;
	long long c { k * ((w * (w + 1)) / 2) };
	if(n > c)
		cout << 0;
	else
		cout << c - n << endl;
}
