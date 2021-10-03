#include <bits/stdc++.h>
using namespace std;

inline
uint8_t
local_max(uint8_t const l, uint8_t const r)
{
    return l > r ? l : r;
}

int main()
{
    unsigned long long T; // duration
    unsigned long long n; // upper time interval count
    unsigned long long m;
    char const * const fmt{ "%llu %llu %llu" };
    scanf(fmt, &T, &n, &m);
    vector<uint8_t> points(T, 0);
    unsigned long long a, b;
    unsigned long long c;
    for(unsigned long long i{ 0U }; i < n; ++i)
    {
        scanf(fmt, &a, &b, &c);
        for(unsigned long long j{ a }; j <= b; ++j)
        {
            points[j] = 2 * c + 1;
        }
    }
    for(unsigned long long i{ 0U }; i < m; ++i)
    {
        scanf(fmt, &a, &b, &c);
        for(unsigned long long j{ a }; j <= b; ++j)
        {
            points[j] = local_max(2 * c + 1, points[j]);
        }
    }
    unsigned long long max_val{ 0U };
    for(auto const point : points)
        max_val += point;
    printf("%llu\n", max_val);
    return EXIT_SUCCESS;
}

