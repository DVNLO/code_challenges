#include <bits/stdc++.h>
using namespace std;

bool is_rbs(std::string const & bracket_sequence)
// returns true if the provided bracket_sequence is a 
// regular bracket sequence
{
    std::stack<char> s;
    size_t const SIZE_BRACKET_SEQUENCE{ bracket_sequence.size() };
    if(SIZE_BRACKET_SEQUENCE % 2)
    {
        return false;
    }
    size_t i{ 0U };
    bool ret{ true };
    while(i < SIZE_BRACKET_SEQUENCE)
    {
        char c{ bracket_sequence[i] };
        if(c == '(')
        {
            s.push(c);
        }
        else if(c == ')')
        {
            if(s.empty())
            {
                ret = false;
                break;
            }
            else if(s.top() == '(' || s.top() == '?')
            {
                s.pop();
            }
        }
        else if(c == '?')
        {
            if(s.empty())
            {
                s.push(c);
            }
            else if(s.top() == '(' || s.top() == '?')
            {
                s.pop();
            }
        }
        else
        {
            ret = false;
            break;
        }
        ++i;
    }
    return ret && s.empty();
}


int main()
{
    int s;  // num test cases
    cin >> s;
    vector<string> bracket_sequences(s);
    for(int i{ 0 }; i < s; ++i)
    {
        cin >> bracket_sequences[i];
    }
    for(int i{ 0 }; i < s; ++i)
    {
        if(is_rbs(bracket_sequences[i]))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
}
