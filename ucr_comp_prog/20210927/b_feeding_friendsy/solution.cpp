#include <bits/stdc++.h>
using namespace std;
int main()
{
    uint64_t T; // duration
    uint64_t n; // upper time interval count
    uint64_t m;
    cin >> T >> n >> m;
    vector<uint32_t> upper(T, 0);
    vector<uint32_t> lower(T, 0);
    for(uint64_t i{ 0U }; i < n; ++i)
    {
        size_t a, b;
        int32_t c;
        cin >> a >> b >> c;
        for(size_t j{ a }; j <= b; ++j)
        {
            if(c == 1)
            {
                upper[j] = 3U;
            }
            else if (c == 0)
            {
                upper[j] = 1U;
            }
            else
            {
                return EXIT_FAILURE;
            }
        }
    }
    for(uint64_t i{ 0U }; i < m; ++i)
    {
        size_t a, b;
        int32_t c;
        cin >> a >> b >> c;
        for(size_t j{ a }; j <= b; ++j)
        {
            if(c == 1)
            {
                lower[j] = 3U;
            }
            else if(c == 0)
            {
                lower[j] = 1U;
            }
            else
            {
                return EXIT_FAILURE;
            }
        }
    }
    uint64_t max_val{ 0U };
//    cout << "####################\n";
    for(uint64_t i{ 0U }; i < T; ++i)
    {
//        cout << i << ' ' << upper[i] << ' ' << lower[i] << '\n';
        max_val += max(upper[i], lower[i]);
    }
    cout << max_val << '\n';
    return EXIT_SUCCESS;
}

