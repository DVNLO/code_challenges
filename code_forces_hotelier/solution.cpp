#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ret = "0000000000";
    for(auto c : s)
    {
        if(c == 'L')
        {
            int i{ 0 };
            while(i < 10 && 
                    ret[i] != '0')
                ++i;
            ret[i] = '1';
        }
        else if(c == 'R')
        {
            int i{ 9 };
            while(i >= 0
                    && ret[i] != '0')
                --i;
            ret[i] = '1';
        }
        else
        {
            ret[c - '0'] = '0';
        }
    }
    cout << ret;
}
