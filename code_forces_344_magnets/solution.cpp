#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    pair<char, char> p;
    cin >> p.first;
    cin >> p.second;
    pair<char, char> c;
    int barrier_count{ 1 };
    for(int i{ 1 }; i < n; ++i)
    {
        if(!isdigit(cin.peek()))
            cin.ignore();
        cin >> c.first;
        cin >> c.second;
        if(p.second == c.first)
            ++barrier_count;
        p.first = c.first;
        p.second = c.second;
    }
    printf("%d\n", barrier_count);
}

        
