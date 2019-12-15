#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int max;
    cin >> v[0];
    max = v[0];
    for(int i{ 1 }; i < n; ++i)
    {
        cin >> v[i];
        if(v[i] > max)
            max = v[i];
    }
    long long w{ 0 };
    for(int i{ 0 }; i < n; ++i)
        w += max - v[i];
    cout << w;
}
