#include <bits/stdc++.h>
using namespace std;
int main()
{
	// how many rooms have a free place for both
	int n; 
	cin >> n;
	int p, q;
	unsigned free_count{ 0 };
	for(int i{ 0 }; i < n; ++i)
	{
		cin >> p >> q;
		if(q - p >= 2)
			++free_count;
	}
	cout << free_count << endl;
}
