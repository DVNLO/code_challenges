#include <bits/stdc++.h>
using namespace std;

long long get_final_pos(long long a, 
                        long long b, 
                        long long k)
{
    return (((k + 1) / 2) * a) - ((k / 2) * b);
}

int main()
{
    int t;
    cin >> t;
    long long a, b, k;
    vector<long long> v(t);
    for(int i{ 0 }; i < t; ++i)
    {
        cin >> a >> b >> k;
        v[i] = get_final_pos(a, b, k);
    }
    for(int i{ 0 }; i < t; ++i)
    {
        cout << v[i] << '\n';
    }
    cout << endl;
}

