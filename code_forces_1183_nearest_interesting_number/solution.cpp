#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a;
	cin >> a;
	int sum_digits;
	int b;
	do
	{
		b = a;
		sum_digits = 0;
		while(b)
		{
			sum_digits += b % 10;
			b /= 10;
		}
		if(sum_digits % 4)
			++a;
		else
			break;
	}
	while(true);
	cout << a << endl;
}
