#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int f0{ 0 };
	int f1{ 1 };
	int i{ 2 };
	int f2;
	while(i <= n)
	{
		f2 = f1 + f0;
		f0 = f1;
		f1 = f2;
		++i;
	}
	if(n <= 0)
	{
		cout << f0;
	}
	else if(n <= 1)
	{
		cout << f1;
	}
	else
	{
		cout << f2;
	}
	cout << endl;
}
