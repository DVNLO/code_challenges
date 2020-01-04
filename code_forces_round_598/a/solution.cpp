#include <bits/stdc++.h>
using namespace std;

void handle_query(int const a, int const b, int const n, int const s)
{
	for(int y{ 0 }; y <= b; ++y)
	{
		if((((s - y) % n) == 0) 
			&& ((s - y) / n) <= a)
		{
			puts("YES");
			return;
		}
	}
	puts("NO");
}


int main()
{
	int q;
	cin >> q;
	int a, b, n, s;
	for(int i{ 0 }; i < q; ++i)
	{	
		cin >> a >> b >> n >> s;
		handle_query(a, b, n, s);
	}
}


