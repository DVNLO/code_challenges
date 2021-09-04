#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/group/1uT235pchJ/contest/342754/problem/A
int main()
{
    int t;
    cin >> t;
    for(long long i{ 0 }; i < t; ++i)
    {
        long long n;
        long long x;
        cin >> n >> x;
        vector<long long> v(n);
        for(long long j{ 0 }; j < n; ++j)
        {
            cin >> v[j];
        }
        long long sum{ 0 };
        long long max{ 0 };
        for(long long j{ 0 }; j < n; ++j)
        {
            sum += v[j];
            max += v[j] / x;
            if(v[j] % x > 0)
            {
                ++max;
            }
        }
        long long min = sum / x;
        if(sum % x > 0)
        {
            ++min;
        }
        cout << min << ' ' << max << '\n';
    }
    return EXIT_SUCCESS;
}

