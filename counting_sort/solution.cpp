#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> & v)
{
    vector<int>::size_type const SIZE{ v.size() };
    int max_val{ v[0] };
    for(vector<int>::size_type i{ 0 }; 
        i < SIZE;
        ++i)
    {
        max_val = max(max_val, v[i]);
    }
    vector<int>::size_type const SIZE_COUNTS{ static_cast<vector<int>::size_type>(max_val + 1) };
    vector<int> counts(SIZE_COUNTS, 0);
    for(vector<int>::size_type i{ 0 };
        i < SIZE;
        ++i)
    {
        ++counts[v[i]];
    }
    vector<int>::size_type i{ 0 };
    vector<int>::size_type j{ 0 };
    while(i < SIZE_COUNTS)
    {
        while(counts[i])
        {
            v[j] = i;
            ++j;
            --counts[i];
        }
        ++i;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i{ 0 }; i < n; ++i)
        cin >> v[i];
    counting_sort(v);
    for(auto const & val : v)
        cout << val << ' ';
    cout << endl;
}
