#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    int x{ 0 };
    for(int i{ 0 }; i < n; ++i)
    {
        cin >> s;
        if(s.size() != 3)
        {
            continue;
        }
        else if(s[1] == '+')
        {
            ++x;
        }
        else if(s[1] == '-')
        {
            --x;
        }
        else
        {
            break;
        }
    }
    cout << x;
}
