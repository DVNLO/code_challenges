#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    string ret;
    for(auto const c : s)
    {
        ret.push_back(c);
        ret.push_back(toupper(c));
    }
    cout << ret;
}
