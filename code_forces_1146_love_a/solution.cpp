#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	unsigned a_count{ 0 };
	for(auto const c : s)
		if(c == 'a')
			++a_count;
	unsigned max_len_good_string;
	if(2 * a_count - 1 > s.size())
		max_len_good_string = s.size();
	else
		max_len_good_string = 2 * a_count - 1;
	printf("%d\n", max_len_good_string);
	return 0;
}
