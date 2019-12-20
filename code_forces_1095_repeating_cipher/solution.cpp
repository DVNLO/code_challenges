#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string::iterator itr{ s.begin() };
    string::iterator END{ s.end() };
    int i{ 1 };
    while(itr < END)
    {
        cout << *itr;
        for(int j{ 0 }; j < i; ++j)
            ++itr;
        ++i;
    }
    cout << endl;
}

