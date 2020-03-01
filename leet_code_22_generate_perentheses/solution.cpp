#include <bits/stdc++.h>
using namespace std;

// This is a tough question for me to wrap my head around writing
// in code. It's easy to work through the theory of the grammar.
// G : S -> (S) || SS || E 
// ^ The grammar G will generate the language of all balanced
// parenthesis. However, implementing this in C is not easy. 
// Hmmm though.


/*
void generate_well_formed_parens(int const n,
                                        vector<string> & parens)
{
	if(n < 0)
		return;
	size_t const MAX_LEN{ static_cast<size_t>(n * 2) };
	size_t s_len;
	queue<string> q;
	string s{ "" };
	q.emplace(s);
	while(!q.empty())
	{
		s = q.front();
		q.pop();
		s_len = s.length();
		if(s_len > MAX_LEN)
			continue;
		else if(s_len < MAX_LEN)
	    	{
			q.emplace('(' + s + ')');
			q.emplace(s + s);
			q.emplace(s);
	    	}
		else
            	{
		    parens.emplace_back(s);
		    cout << s << '\n';
		}
	}
}
*/

// UGH this is bad. This is an odd case where knowing the theory
// is hindering my ability to be creative. I'm continually trying to fit
// the grammar approach into this code to no avail. Very odd.
void generate_parens(set<string> & parens, 
			int const n)
{
	if(n <= 0)
		return;
	set<string> new_parens;
	for(auto const paren : parens)
	{
		new_parens.insert(paren);
		new_parens.insert('(' + paren + ')');
		new_parens.insert(paren + paren);
	}
	generate_parens(new_parens, n - 1);
	parens = new_parens;
}

// this is kind of like a back tracking solution but it's not valid 
string generate_parens(string s, int n)
{
	if(!n)
		return s;
	return generate_parens('(' + s + ')', n - 1);
	return generate_parens(s, n) + generate_parens(s, n);
}

int main()
{
	int n;
	cin >> n;
	set<string> parens{ "" };
	generate_parens(parens, n);
	for(auto const paren : parens)
		cout << paren << '\n';
}	
