// The following is my solution to https://codeforces.com/problemset/problem/677/A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, h;
    cin >> n >> h;
    int min_width{ n };
    int val;
    for(int i{ 0 }; i < n; ++i)
    {
        cin >> val;
        if(val > h)
            ++min_width;
    }
    cout << min_width;
}
