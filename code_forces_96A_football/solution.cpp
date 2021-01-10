#include <bits/stdc++.h>
using namespace std;

bool is_dangerous(string const & s)
// returns true if the provided string s is 
// dangerous. A string is dangerous if it 
// contains at least danger threshold consecutive 
// symbols.
{
    size_t constexpr DANGER_THRESHOLD{ 7U };
    size_t const SIZE_S{ s.size() };
    for(size_t i{ 0U }; i < SIZE_S; ++i)
    {
        size_t j{ i + 1 };
        while(j < SIZE_S 
              && s[i] == s[j])
        {
            ++j;
        }
        if(j - i >= DANGER_THRESHOLD)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s;
    cin >> s;
    bool danger{ is_dangerous(s) };
    if(danger)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

