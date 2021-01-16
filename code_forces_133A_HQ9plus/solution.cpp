#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    bool will_output{ false };
    for(char c : s)
    {
        switch(c)
        {
            case 'H' : case 'Q' : case '9':
                will_output = true;
            default:
                break;
        }
        if(will_output)
            break;
    }
    if(will_output)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
