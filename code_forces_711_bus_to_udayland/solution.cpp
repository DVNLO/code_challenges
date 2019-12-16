#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string row;
    vector<string> bus(n);
    bool seated{ false };
    for(int i{ 0 }; i < n; ++i)
    {
        cin >> row;
        if(!seated && (row[0] == 'O'&& row[1] == 'O'))
        {
            row[0] = '+';
            row[1] = '+';
            seated = true;
        }
        else if(!seated && (row[3] == 'O' && row[4] == 'O'))
        {
            row[3] = '+';
            row[4] = '+';
            seated = true;
        }
        bus[i] = row;
    }
    if(seated)
    {
        cout << "YES\n";
        for(int i{ 0 }; i < n; ++i)
            cout << bus[i] << '\n';
    }
    else
        cout << "NO\n";
}
