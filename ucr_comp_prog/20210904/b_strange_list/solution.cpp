#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/group/1uT235pchJ/contest/342754/problem/B

long long
div_count(long long val, long long q)
{
    long long ret{ 0 };
    while(val % q == 0)
    {
        val /= q;
        ++ret;
    }
    return ret;
}

int main()
{
    int t;
    cin >> t;
    for(int i{ 0 }; i < t; ++i)
    {
        size_t n;
        long long x;
        cin >> n >> x;
        vector<long long> v(n);
        for(size_t j{ 0 }; j < n; ++j)
        {
            cin >> v[j];
        }
        long long sum{ 0 };
        long long min_d{ div_count(v[0], x) };
        for(size_t j{ 0 }; j < n; ++j)
        {
            long long const q{ v[j] };
            min_d = min(min_d, div_count(q, x));
            sum += q + q * min_d;
        }
        cout << sum << '\n';
    }
    return EXIT_SUCCESS;
}

