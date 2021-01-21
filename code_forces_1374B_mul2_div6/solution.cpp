#include <bits/stdc++.h>
using namespace std;

int
mul2_and_div6(int n)
{
    int steps{ 0 };
    while(n > 1)
    {
        ++steps;
        if(n % 6 == 0)
        {
            n /= 6;
        }
        else if(n % 3 == 0)
        {
            n *= 2;
        }
        else
        {
            steps = -1;
            break;
        }
    }
    return steps;
}

int main()
{
    int t;
    cin >> t;
    vector<int> v(t);
    for(int i { 0 }; i < t; ++i)
    {
        cin >> v[i];
        v[i] = mul2_and_div6(v[i]);
    }
    for(int i { 0 }; i < t; ++i)
    {
        cout << v[i] << '\n';
    }
    cout << endl;
}


