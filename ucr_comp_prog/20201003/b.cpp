#include <bits/stdc++.h>
using namespace std;

inline bool 
swallow(int ai, int aj, int k)
{
    return (ai > aj) && (ai <= (aj + k));
}

// not accepted due to timeout. The solution presented utilized a map
// to keep order and to guarentee uniqueness, that 
// way we wouldn't need to make the runs that my code is making
// in the inner while.

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(size_t i{ 0U }; i < n; ++i)
        cin >> A[i];
    sort(A.begin(), A.end());
    if(A.size() > 1)
    {
        for(size_t i{ 1U }; i < n; ++i)
        {
            size_t j{ i - 1 };
            while(j < n && swallow(A[i], A[j], k))
            {
                A[j] = 0;
                --j;
            }
        }
    }
    int remaining_count{ 0 };
    for(size_t i{ 0 }; i < n; ++i)
    {
        // cout << A[i] << ' ';
        if(A[i])
            ++remaining_count;
    }
    // cout << endl;
    cout << remaining_count << endl;
}
