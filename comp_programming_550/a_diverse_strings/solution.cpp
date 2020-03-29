#include <bits/stdc++.h>
using namespace std;

// Solution not accepted. Problem statement is not well formed. 
// Cannot determine what it is asking for after reviewing the test cases.
// See the attached excel doc. Moving on. 

string is_diverse(string const & s)
{
	int const SIZE_S{ static_cast<int>(s.size()) };
	static string const YES{ "Yes" };
	static string const NO{ "No" };
	if(SIZE_S == 1)
		return YES;
	unordered_map<char, char> adjacent_symbols;
	bool contains_adjacent{ false };
	for(int i{ SIZE_S - 1 }; i >= 0; --i)
	{
		if(adjacent_symbols.count(s[i]))
			return NO;
		else
			adjacent_symbols[s[i]] = static_cast<char>(s[i] + 1);
		if(!contains_adjacent
			&& adjacent_symbols.count(adjacent_symbols[s[i]]))
			contains_adjacent = true;
	}
	if(contains_adjacent)
		return YES;
	else
		return NO;

}

int main()
{
	// a string is diverse if it constain adjacent letters of latin alphabet
	// and each letter occurs exactly once, no duplicates
	int n;
	cin >> n;
	string in;
	vector<string> output;
	for(int i{ 0 }; i < n; ++i)
	{
		cin >> in;
		string out = is_diverse(in);
		output.emplace_back(out);
	}
	for(auto const & out : output)
	{
		cout << out << '\n';
	}
	cout << endl;
}
