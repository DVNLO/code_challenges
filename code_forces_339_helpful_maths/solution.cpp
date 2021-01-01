#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    unsigned counts[3] = { 0, 0, 0 };
    for(char const c : s)
    {
        if(c == '1' || c == '2' || c == '3')
        {
            ++counts[c - '1'];
        }
    }
    s.clear();
    for(char i{ 0U }; i < 3; ++i)
    {
        char const c{ static_cast<char>('1' + i) };
        while(counts[i])
        {
            s.push_back(c);
            s.push_back('+');
            --counts[i];
        }
    }
    s.pop_back();
    cout << s;
}
