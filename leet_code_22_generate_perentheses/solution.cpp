#include <bits/stdc++.h>
using namespace std;

// Okay so I came back to the problem much later. I finally wrapped my
// mind around it. While the theory below is helpful, it was easier
// to think of how to implement this from a decision tree perspective.
// Suppose we have a string s, and we wish to generate the set of all
// balanced parenthesis for n parentheses. Well, if we begin
// from an arbitrary string s, we can suppose that there are two 
// options, to either add an opening paren or add a closing paren.
// However, we can only add a closing paren if we previousily added
// at least one opening paren. Therefore we have established some
// invariants on which we can recurse. In the base case, we add s
// to the set of balanced parens if we have 0 opening and closing
// parens to add remaining. By this logic, I wrote the following 
// code which was submitted and accepted.

class Solution2 {
public:
    void
    generate_parens(string const s,
                    int const open_cnt,
                    int const close_cnt,
                    vector<string> & parens)
    {
        if(open_cnt < 0 || close_cnt < 0)
        {
            return;
        }
        if(!open_cnt && !close_cnt)
        {
            parens.emplace_back(s);
            return;
        }
        if(open_cnt > 0)
        {
            generate_parens(s + '(', open_cnt - 1, close_cnt, parens);
        }
        if(close_cnt > 0 && open_cnt < close_cnt)
        {
            generate_parens(s + ')', open_cnt, close_cnt - 1, parens);
        }
    }

    vector<string>
    generateParenthesis(int n)
    {
        vector<string> ret;
        generate_parens("", n, n, ret);
        return ret;
    }
};


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
