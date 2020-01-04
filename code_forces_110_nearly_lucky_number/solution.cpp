#include <bits/stdc++.h>
using namespace std;
int main()
{
	// lucky numbers contain only digits 4 and 7
	// a number is lucky if the number of lucky digits in it is a lucky number
	string s;
	cin >> s;
	size_t const size{ s.size() };
	unsigned lucky_number_count{ 0U };
	for(int i{ 0 }; i < size; ++i)
	{
		if(s[i] == '4'
			|| s[i] == '7')
			++lucky_number_count;
	}
	if(lucky_number_count == 4 || lucky_number_count == 7)
		puts("YES");
	else
		puts("NO");
}
