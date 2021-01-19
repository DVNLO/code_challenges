#include <bits/stdc++.h>
using namespace std;

int 
get_unique_pair_target_sum_count(std::vector<int> v, int const t)
// returns the number of unique pairs p = (a, b) such that a + b = t.
{
    std::set<int> vals{ begin(v), end(v) };
    std::set<int> complements;
    for(auto const a : vals)
    {
        if(complements.count(a))
        {
            continue;
        }
        if(vals.count(t - a))
        {
            complements.insert(t - a);
        }
    }
    return complements.size();
}

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for(int i{ 0 }; i < n; ++i)
    {
        cin >> v[i];
    }
    cout << get_unique_pair_target_sum_count(v, t) << endl;
}
