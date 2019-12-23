#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i{ 0 }; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    long long total_solve_count{ 0 };
    for(int i{ 0 }; i < n; i+=2)
    {
        total_solve_count += v[i + 1] - v[i];
    }
    cout << total_solve_count << endl;
}

