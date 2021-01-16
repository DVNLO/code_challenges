#include <bits/stdc++.h>
using namespace std;

size_t 
get_max_len_non_decreasing_subsegment(vector<int>::const_iterator l,
                                      vector<int>::const_iterator r)
{
    size_t max_len{ 0U };
    vector<int>::const_iterator m{ l + 1 };
    while(l < r)
    {
        m = l + 1;
        while(m < r && *m >= *(m - 1))
        {
            ++m;
        }
        static_assert(sizeof(size_t) == sizeof(ptrdiff_t));
        assert(m >= l);
        size_t const len{ static_cast<size_t>(m - l) };
        if(len > max_len )
        {
            max_len = len;
        }
        l = m;
    }
    return max_len;
}

int main()
{
    size_t n;
    cin >> n;
    vector<int> vals(n);
    for(size_t i{ 0U }; i < n; ++i)
    {
        cin >> vals[i];
    }
    cout 
        << get_max_len_non_decreasing_subsegment(begin(vals), end(vals)) 
        << endl;
}
