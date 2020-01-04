#include <bits/stdc++.h>
using namespace std;

void handle_query(int const n, int const k, string & s)
{
	int swap_count{ 0 };
	int forward_pos{ 0 };
	int backward_pos;
	while(swap_count < k)
	{
		while(forward_pos < n
			&& s[forward_pos] != '0')
			++forward_pos;
		if(forward_pos >= n)
			break;
		backward_pos = forward_pos;
		while(backward_pos > 0
			&& s[backward_pos - 1] == '1'
			&& swap_count < k)
		{
			swap(s[backward_pos - 1], s[backward_pos]);
			++swap_count;
			--backward_pos;
		}
	}
	cout << s << '\n';
}


int main()
{
	int q;
	cin >> q;
	int n, k;
	string s;
	for(int i{ 0 }; i < q; ++i)
	{
		cin >> n >> k;
		cin >> s;
		handle_query(n, k, s);
	}
	cout << endl;
}		
