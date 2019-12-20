#include <bits/stdc++.h>
using namespace std;

int max_profit(int b, int p, int f, 
                int h, int c)
{
    int ham_count{ 0 };
    int chicken_count{ 0 };
    if(h >= c)
    {
        do
        {
            ++ham_count;
        }
        while(2 * ham_count < b 
                && ham_count < p);  // maximize ham_count
        if(2 * ham_count > b 
            || ham_count > p)   // correct off by one
            --ham_count;
        b -= 2 * ham_count; // the burgers with ham
        chicken_count = min(b / 2, f);  // the remainder are used for chicken if there are enough f, patties
    }
    else
    {
        do
        {
            ++chicken_count;
        }
        while(2 * chicken_count < b 
                && chicken_count < f);  // maximize chicken_count
        if(2 * chicken_count > b 
            || chicken_count > f)   // correct off by one
            --chicken_count;
        b -= 2 * chicken_count; 
        ham_count = min(b / 2, p);  // the remainder are used for ham if there are enough p, patties.
    }
    return h * ham_count + c * chicken_count;
}

int main()
{
    int t;
    cin >> t;
    vector<int> v(t);
    int b, p, f;
    int h, c;
    for(int i{ 0 }; i < t; ++i)
    {
        cin >> b >> p >> f
            >> h >> c;
        v[i] = max_profit(b, p, f, h, c);
    }
    for(auto const val : v)
        cout << val << endl;
}

