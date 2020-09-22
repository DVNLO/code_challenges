#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin, s);
    if(s.empty())
    {
        cout << "yes\n";
        return EXIT_SUCCESS;
    }
    unordered_map<char, size_t> symbol_counts;
    for(char const c : s)
    {
        if(c == ' ')    // ignore spaces based on the example
        {
            continue;
        }
        char const cur = tolower(c);
        if(!symbol_counts.count(cur))
        {
            symbol_counts.insert({ cur, 1U });
        }
        else
        {
            ++symbol_counts[cur];
        }
    }
    size_t odd_count{ 0U };
    for(auto const symbol_count : symbol_counts)
    {
        if(symbol_count.second % 2)
        {
            ++odd_count;
            if(odd_count > 1)
            {
                break;
            }
        }
    }
    if(odd_count > 1)
    {
        cout << "no\n";
    }
    else
    {
        cout << "yes\n";
    }
    return EXIT_SUCCESS;
}
