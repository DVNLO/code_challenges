#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count{ 0 };
    for(auto const c : s)
    {
        if(c == '(')
            ++count;
        else
            --count;
        if(count < -1)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    if(count)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
