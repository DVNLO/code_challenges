#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int two_count;
    int three_count;
    if(n & 0x1) // is odd
    {
        two_count = n / 2 - 1;
        three_count = 1;
    }
    else
    {
        two_count = n / 2;
        three_count = 0;
    }
    cout << two_count + three_count << '\n';
    string s;
    for(int i{ 0 }; i < two_count; ++i)
        s += "2 ";
    for(int i{ 0 }; i < three_count; ++i)
        s += "3 ";
    cout << s << '\n';
}
