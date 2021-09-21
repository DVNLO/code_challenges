#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t n;
    int64_t m;
    int64_t a;
    // theatre square has dimension n x m
    // cover the square with tiles of dimension a x a
    cin >> n >> m >> a;
    int64_t flagstone_count{ 0 };
    /* O(n^2) solution
    for(int i{ 0 }; i < n; i += a)
    {
        for(int j{ 0 }; j < m; j += a)
        {
            ++flagstone_count;
        }
    }
    */
    // O(1) solution.
    int64_t x{ n / a };
    if(n % a)
    {
        x += 1;
    }
    int64_t y{ m / a };
    if(m % a)
    {
        y += 1;
    }
    flagstone_count = x * y;
    cout << flagstone_count << endl;
}
