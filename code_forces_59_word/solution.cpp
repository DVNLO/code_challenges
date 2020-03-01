#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	unsigned upper_count{ 0U };
	unsigned lower_count{ 0U };
	for(auto const c : s)
	{
		if(islower(c))
			++lower_count;
		else if(isupper(c))
			++upper_count;
	}
	if(lower_count >= upper_count)
	{
		for(auto & c : s)
			c = static_cast<char>(tolower(c));
	}
	else
	{
		for(auto & c : s)
			c = static_cast<char>(toupper(c));
	}
	cout << s << endl;
}
