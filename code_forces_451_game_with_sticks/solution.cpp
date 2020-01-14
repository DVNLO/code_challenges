#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; // horizontal
	int m; // vertical
	cin >> n >> m;
	int intersections{ min(n, m) };
	if(intersections & 0x1)
	{
		puts("Akshat");
	}
	else
	{
		puts("Malvika");
	}
}
